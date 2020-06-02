#include "UI.h"
#include <assert.h>

void testDomain(){
    // This function tests the Domain: the Movie class
    Movie m{"Name","Genre",1234,0,"link"};
    assert(m.getTitle() == "Name" );
    assert(m.getLink() == "link");
    assert(m.getGenre() == "Genre");
    assert(m.getYear() == 1234);
    assert(m.getLikes() == 0);
    m.setLike(2);
    m.setLink("linkss");
    m.setYear(321);
    m.setGenre("aaaa");
    assert(m.getLink() == "linkss");
    assert(m.getGenre() == "aaaa");
    assert(m.getYear() == 321);
    assert(m.getLikes() == 2);
    std::string test_string = m.getTitle() + ' ' + m.getGenre() + ' ' + std::to_string(m.getYear()) + ' ' + std::to_string(m.getLikes()) + ' ' + m.getLink() + '\n' ;
    assert(m.toString() == test_string);
}


void testRepository(){
    Repository test_repo;
    assert(test_repo.getSize() == 0);
    Movie movie1{"JohnWick", "Action", 2019, 0, "https://www.youtube.com/watch?v=pU8-7BX9uxs"};
    Movie movie2{"Fast&Furious", "Action", 2019, 0, "https://www.youtube.com/watch?v=nYTRzYZrcUg"};
    Movie movie3{"Split", "Horror", 2017, 0, "https://www.youtube.com/watch?v=mJXACd2zAx8"};
    test_repo.addMovie(movie1);
    test_repo.addMovie(movie2);
    test_repo.addMovie(movie3);
    assert(test_repo.getSize() == 3);
    assert(test_repo.check_movie("Split") == true);
    assert(test_repo.check_movie("Xasd") == false);
    test_repo.delete_movie("JohnWick");
    assert(test_repo.getSize() == 2);
    assert(test_repo.check_movie("JohnWick") == false);
    test_repo.like_movie("Split");
    test_repo.update_movie("Split","dddd",12312,"linsdsd");
}

void testController(){
    Repository test_repo;
    assert(test_repo.getSize() == 0);
    Movie movie1{"JohnWick", "Action", 2019, 0, "https://www.youtube.com/watch?v=pU8-7BX9uxs"};
    Movie movie2{"Fast&Furious", "Action", 2019, 0, "https://www.youtube.com/watch?v=nYTRzYZrcUg"};
    Movie movie3{"Split", "Horror", 2017, 0, "https://www.youtube.com/watch?v=mJXACd2zAx8"};
    Controller ctrl{test_repo};
    assert(ctrl.getWatchlistSize() == 0);
    ctrl.addMovieToWatchlist(movie1);
    assert(ctrl.getWatchlistSize() == 1);
    ctrl.deleteMovie("Fast&Furious");
    assert(ctrl.checkMovieInWatchlist(movie2) == false);
    assert(ctrl.checkMovieInWatchlist(movie1) == true);
}

void testAll(){
    testDomain();
    testRepository();
    testController();
}
int main() {
    testAll();
    Repository repo;

    Movie movie1{"JohnWick", "Action", 2019, 0, "https://www.youtube.com/watch?v=pU8-7BX9uxs"};
    Movie movie2{"Fast&Furious", "Action", 2019, 0, "https://www.youtube.com/watch?v=nYTRzYZrcUg"};
    Movie movie3{"Split", "Horror", 2017, 0, "https://www.youtube.com/watch?v=mJXACd2zAx8"};
    repo.addMovie(movie1);
    repo.addMovie(movie2);
    repo.addMovie(movie3);

    Controller ctrl{repo};
    Console ui{ctrl};
    ui.run();

    std::cout << repo.check_movie("Split");
    return 0;
}