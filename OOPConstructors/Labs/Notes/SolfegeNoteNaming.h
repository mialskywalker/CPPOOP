//
// Created by uchih on 26.7.2024 г..
//

#ifndef SOLFEGENOTENAMING_H
#define SOLFEGENOTENAMING_H

#include "NoteName.h"

class SolfegeNoteNaming {
public:
    NoteName operator() (const std::string& noteText) const {
        switch (noteText[0]) {
            case 'D': return NoteName('C');
            case 'R': return NoteName('D');
            case 'M': return NoteName('E');
            case 'F': return NoteName('F');
            case 'L': return NoteName('A');
            case 'S': return (noteText == "Sol" ? 'G' : 'B');
            default:
                return '?';
        }
    }
};

#endif //SOLFEGENOTENAMING_H
