
#include "Keyboard.h"
namespace piano {
    Keyboard::Keyboard(){}

    Keyboard::Keyboard(std::string octave) {
        octave_ = octave;
        key_map_.insert(std::pair<std::string, Key>("C", Key("C", 0, "white", octave)));
        key_map_.insert(std::pair<std::string, Key>("D", Key("D", 1, "white", octave)));
        key_map_.insert(std::pair<std::string, Key>("E", Key("E", 2, "white", octave)));
        key_map_.insert(std::pair<std::string, Key>("F", Key("F", 3, "white", octave)));
        key_map_.insert(std::pair<std::string, Key>("G", Key("G", 4, "white", octave)));
        key_map_.insert(std::pair<std::string, Key>("A", Key("A", 5, "white", octave)));
        key_map_.insert(std::pair<std::string, Key>("B", Key("B", 6, "white", octave)));
        key_map_.insert(std::pair<std::string, Key>("C#", Key("C#", 0, "black", octave)));
        key_map_.insert(std::pair<std::string, Key>("D#", Key("D#", 1, "black", octave)));
        key_map_.insert(std::pair<std::string, Key>("F#", Key("F#", 3, "black", octave)));
        key_map_.insert(std::pair<std::string, Key>("G#", Key("G#", 4, "black", octave)));
        key_map_.insert(std::pair<std::string, Key>("A#", Key("A#", 5, "black", octave)));

    }

    const std::map<std::string, Key> Keyboard::GetKeys() const {
        return key_map_;
    }

    void Keyboard::Display() {
        DrawAllKeys();
        ci::gl::color(ci::Color(kKeyboardTopColor));
        ci::gl::drawSolidRect(
                ci::Rectf(kKeyboardTopLowerPos, kKeyboardTopUpperPos));
       UpdateHighlight();
    }

    void Keyboard::DrawAllKeys() {
        size_t margin = 0;
        std::map<std::string, Key>::iterator it;
        for (it = key_map_.begin(); it != key_map_.end(); it++) {
            ci::gl::color(ci::Color(it->second.GetColor()));
            it->second.SetKeyCoords(vec2(kCKeyLowerPos.x + margin, kCKeyLowerPos.y),
                                    vec2(kCKeyUpperPos.x + margin, kCKeyUpperPos.y));
            it->second.DrawKey(it->second.GetLowerKeyCoords(), it->second.GetUpperKeyCoords());
            margin += kGapBetweenKeys;
        }
    }

    void Keyboard::PlayGivenNote(std::string letter) {
        key_map_.at(letter).PlayNote();
        recentPlayedKey_ = key_map_.at(letter);
    }

    Key& Keyboard::FindKeyWithLetter(std::string letter)  {
        std::map<std::string, Key>::iterator it;
        for (it = key_map_.begin(); it != key_map_.end(); it++) {
            if (it->second.GetNote() == letter) {
                return it->second;
            }
        }
        return it->second;
    }

   bool Keyboard::UpdateHighlight() const {
        if (key_map_.count(recentPlayedKey_.GetNote()) > 0) {
            key_map_.at(recentPlayedKey_.GetNote()).Highlight();
            return true;
        }
        return false;
    }

    Key& Keyboard::GetRecentPlayedKey() {
        return recentPlayedKey_;
    }

    int Keyboard::GetOctave() const {
        return stoi(octave_);
    }
}