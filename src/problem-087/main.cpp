// depends on fnc12/sqlite_orm
#include <sqlite_orm/sqlite_orm.h>
// depends on tanakah/cmdline
#include "cmdline.h"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

namespace DataModel {
    struct Movie {
        int id;
        std::string title;
        int year;
        int length;
    };

    struct Person {
        int id;
        std::string name;
    };

    struct Director {
        int id;
        int movieId;
        int personId;
    };

    struct Writer {
        int id;
        int movieId;
        int personId;
    };

    struct Casting {
        int id;
        int movieId;
        int personId;
        std::string role;
    };

    struct Media {
        int id;
        int movieId;
        std::string name;
        std::string description;
        std::vector<char> content;
    }
}

static auto initStorage(const std::string& path) {
    using namespace DataModel;
    using namespace sqlite_orm;
    auto storage = make_storage(
        path,
        make_table("movies",
            make_column("id",          &Movie::id, primary_key()),
            make_column("title",       &Movie::title),
            make_column("year",        &Movie::year),
            make_column("length",      &Movie::length)
        ),
        make_table("persons",
            make_column("id",          &Person::id, primary_key()),
            make_column("title",       &Person::name)
        ),
        make_table("directors",
            make_column("id",          &Director::id, primary_key()),
            make_column("movieid",     &Director::movieId),
            make_column("personid",    &Director::personId)
        ),
        make_table("casting",
            make_column("id",          &Casting::id, primary_key()),
            make_column("movieid",     &Casting::movieId),
            make_column("personid",    &Casting::personId),
            make_column("role",        &Casting::role)
        ),
        make_table("media",
            make_column("id",          &Media::id, primary_key()),
            make_column("movieid",     &Media::movieId),
            make_column("name",        &Media::name),
            make_column("description", &Media::description),
            make_column("content",     &Media::content) // blob
        ),
    );
    return storage;
}

int main(int argc, char* argv[]) {
    using namespace std;
    using namespace DataModel;
    using Storage = decltype(initStorage(""));

    Storage storage = initStorage("db.sqlite");
    storage.sync_schema();

    // a.out --action add --type media --media_name package_image --description test_description --media_file /path/to/media
    cmdline::parser a;
    a.add<string>("action",            "a",  "add,remove", false, "show"); // todo: init, remove, show, ...
    a.add<string>("type",              "t",  "media", false, "all");       // todo: movie, person, director, casting, ....
    a.add<int>(   "movie_id",          "\0", "target movie id", true, "");
    a.add<int>(   "media_id",          "\0", "target media id", true, "");
    a.add<string>("media_name",        "\0", "media file name", true, "");
    a.add<string>("media_description", "\0", "media file name", true, "");
    a.add<string>("media_file",        "\0", "media file path", true, "");

    a.parse_check(argc, argv);

    if (a.get<string>("action") == "add") {
        if (a.get<string>("type") == "media") {
            const int movieId        = a.get<int>("movie_id");
            const string name        = a.get<string>("media_name");
            const string description = a.get<string>("media_description");
            const string filePath    = a.get<string>("media_file");
            // todo: args validation

            vector<char> bin;
            ifstream ifs(filePath, std::ios::binary);
            bin.assign(istream_iterator<char>(ifs), istream_iterator<char>());

            Media media {
                0,
                movieId
                name,
                description,
                bin,
            };
            storage.insert(media);
        }
    } else if (a.get<string>("action") == "remove") {
        if (a.get<string>("type") == "media") {
            const int mediaId = a.get<int>("media_id");
            storage.remove<Media>(mediaId);
        }
    }
    
    return 0;
}