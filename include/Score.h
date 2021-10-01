
#ifndef FINAL_PROJECT_ADITIK4_SCORE_H
#define FINAL_PROJECT_ADITIK4_SCORE_H

#include "cinder/gl/gl.h"
#include "Keyboard.h"
#include <glm/vec2.hpp>

namespace piano {
    class Score {
    public:
        /**
         * Constructs a score object.
         */
        Score();
        /**
         * Draws a score with lines and a box.
         */
        void DrawScore() const;
        /**
         * Draws the recent played note on the screen
         * @param key the key that was played
         * @param pos the position to draw the note
         */
        void DrawNextNote(Key& key, vec2 pos) const;
        /**
         * Displays the score on the screen
         */
        void Display();
        /**
         * Sets the note to draw next
         * @param note the note to draw
         */
        void SetNoteToDraw(Key& note);
        /**
         * Draws all notes on the score
         */
        void DrawAllNotes();
        /**
         * Obtains the position of the recent played note
         * @param key the key for which to find position
         * @return a vec2 of the next key's position
         */
        vec2 GetNextNotePosition(Key& key) const;
        /**
         * Clears the score such that there are no notes on staff
         */
        void ClearScore();
        /**
         * Draws each line of the score.
         * @param lineOrder
         */
        void DrawNextLine(size_t lineOrder) const;
        /**
         * Returns the vector of positions
         * @return thee vector of positions of notes on score
         */
        std::vector<vec2> GetAllNotePositions() const;
    private:
        /**
         * Stores the color of the score box
         */
        cinder::ColorT<float> kScoreColor = "pink";
        /**
         * Stores the lower coordinates of the box
         */
        vec2 kScoreBoxLower = vec2(20, 370);
        /**
         * Stores the upper coordinates of the box
         */
        vec2 kScoreBoxUpper = vec2(600, 570);

        /**
         * Stores the lowest line upper position of the score
         */
        glm::vec2 kELineUpper = vec2(20, 520);
        /**
         * Stores the lowest line lower position of the score
         */
        glm::vec2 kELineLower = vec2(600, 520);

        /**
         * Stores the position of middle C on staff
         */
        vec2 kCLine = vec2(kELineUpper.x, kELineUpper.y + 30);
        /**
         * Stores the positions of all keys played
         */
        std::vector<vec2> all_played_positions_;
        /**
         * Stores all keys that have been played
         */
        std::vector<Key> all_played_keys_;
        /**
         * Stores the width between lines
         */
        size_t width_between_lines = 30;
        /**
         * Stores the gap between each note on staff
         */
        size_t note_margin_ = 10;
        /**
         * Stores the radius of each note
         */
        size_t kRadius = 15;
        /**
         * Stores the color of each note's display lettering
         */
        cinder::ColorT<float> kNoteStringColor = "black";
        /**
         * Stores the margin between note position on staff
         */
        size_t kGapBetweenNotes = 25;
        /**
         * Stores the color of each line
         */
        cinder::ColorT<float> kLineColor = "white";
    };
}


#endif //FINAL_PROJECT_ADITIK4_SCORE_H
