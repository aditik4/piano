
#include "Score.h"

namespace piano {

    Score::Score() {
        all_played_keys_ = std::vector<Key>();
        all_played_positions_ = std::vector<vec2>();
    }

    void Score::DrawScore() const {
        ci::gl::color(ci::Color(kScoreColor));
        ci::gl::drawStrokedRect(ci::Rectf(kScoreBoxLower, kScoreBoxUpper));
        DrawNextLine(0);
        DrawNextLine(1);
        DrawNextLine(2);
        DrawNextLine(3);
        DrawNextLine(4);
    }

    void Score::DrawNextLine(size_t lineOrder) const{
        ci::gl::color(ci::Color(kLineColor));
        ci::gl::drawLine(vec2(kELineLower.x, kELineLower.y - (width_between_lines * lineOrder)), vec2(kELineUpper.x, kELineUpper.y -(width_between_lines * lineOrder)));
    }

    void Score::Display() {
        DrawScore();
        DrawAllNotes();
    }

    void Score::SetNoteToDraw(Key& note) {
        note_margin_ += kGapBetweenNotes;
        all_played_keys_.push_back(note);
        all_played_positions_.push_back(GetNextNotePosition(note));
        if (GetNextNotePosition(note).x >= kScoreBoxUpper.x) {
            ClearScore();
        }
    }
    void Score::DrawNextNote(Key& key, vec2 pos) const{
        ci::gl::drawSolidCircle(pos, kRadius);
        ci::gl::drawString(key.GetNote(),vec2(pos.x - 5, pos.y), kNoteStringColor);
    }

    vec2 Score::GetNextNotePosition(Key& key) const{
        return vec2(kCLine.x + note_margin_, kCLine.y - ((kRadius * key.GetNumStepsFromC()) + (105 * stoi(key.GetOctave()))));
    }

    void Score::DrawAllNotes() {
        size_t i = 0;
        for(Key& key: all_played_keys_) {
            DrawNextNote(key, all_played_positions_.at(i));
            i++;
        }
    }

    void Score::ClearScore() {
        all_played_keys_.clear();
        all_played_positions_.clear();
        note_margin_ = 0;
    }

    std::vector<vec2> Score::GetAllNotePositions() const {
        return all_played_positions_;
    }

}