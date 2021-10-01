#define CATCH_CONFIG_MAIN
#include <catch2/catch.hpp>
#include <Score.h>
#include <piano_simulation_app.h>

//using piano::Keyboard;
//using piano::Key;
using piano::Score;
using piano::Keyboard;


TEST_CASE("Tests if keys are added into map with appropriate values") {
    Keyboard keyboard = Keyboard(0);
    REQUIRE(keyboard.GetKeys().size() == 12);
    REQUIRE(keyboard.FindKeyWithLetter("C").GetNumStepsFromC() == 0);
    REQUIRE(keyboard.FindKeyWithLetter("D").GetNumStepsFromC() == 1);
    REQUIRE(keyboard.FindKeyWithLetter("E").GetNumStepsFromC() == 2);
    REQUIRE(keyboard.FindKeyWithLetter("F").GetNumStepsFromC() == 3);
    REQUIRE(keyboard.FindKeyWithLetter("G").GetNumStepsFromC() == 4);
}
TEST_CASE("Tests if recent key is updated") {
    Keyboard keyboard = Keyboard(0);
    keyboard.PlayGivenNote("C");
    REQUIRE(keyboard.GetRecentPlayedKey().GetNote() == "C");
    keyboard.PlayGivenNote("D");
    REQUIRE(keyboard.GetRecentPlayedKey().GetNote() == "D");
}
TEST_CASE("Tests recent played key is highlighted") {
    Keyboard keyboard = Keyboard(0);
    keyboard.PlayGivenNote("C");
    REQUIRE(keyboard.UpdateHighlight() == true);
}

TEST_CASE("Tests set note to draw") {
    Keyboard keyboard = Keyboard(0);
    Score score = Score();
    score.SetNoteToDraw(keyboard.FindKeyWithLetter("C"));
    REQUIRE(score.GetAllNotePositions().size() == 1);
    REQUIRE(score.GetAllNotePositions().at(0) == vec2(20, 550));
}
TEST_CASE("Tests clear score") {
    Keyboard keyboard = Keyboard(0);
    Score score = Score();
    score.SetNoteToDraw(keyboard.FindKeyWithLetter("C"));
    REQUIRE(score.GetAllNotePositions().size() == 1);
    score.ClearScore();
    REQUIRE(score.GetAllNotePositions().size() == 0);

}