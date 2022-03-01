//
//  RDPHeader.cpp
//  comp252Project
//
//  Created by Wataru Oshima on 2020/05/10.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#include "RDPHeader.h"
#include <iostream>

struct node {
    int data;
    struct node *next;
};

node *start=NULL;
node *createNode(){
    node *temp;
    temp = new node;
    return temp;
}


int RDPH::searchNDL(int deapthInput)
{
    //searching NDP but need to fix it to be more efficient
    if (deapthInput > 42) {
        return 0;
    }
    else {
        for (int i = 0; i<length; i++) {
            if (deapthInput == deapth[i])
            {
                return NDL[i];
            }
        }
    }
    return -1;
}

void RDPH::initializeNode()
{
    node *temp, *traverse;
    int range = 0;
    for (int i = range; i<12; i++) {
        temp = createNode();
        temp->data = deapth[i];
        temp->next = NULL;
        if (start == NULL) {
            start = temp;
        }
        else
        {
            traverse = start;
            while(traverse->next != NULL){
                traverse= traverse->next;
            }
            traverse->next= temp;
            }
        }
}

void RDPH::println()
{
    int j = 1;
    node *traverseNode = start;

    while(traverseNode != NULL){
        std::cout<<traverseNode->data<< " ";
        traverseNode = traverseNode->next;
        j = ++j;
        }
    std::cout<< std::endl;
}



std::string RDPH::searchPG(int deapthInput, int divingTime)
{
    std::string pressureGroup;
    int listForPG = 0;
    switch (deapthInput) {
        case 10:
            listForPG = 0;
            pressureGroup = RDPH::caluculatePG(divingTimeFor10, 26, divingTime);
            break;
        case 12:
            listForPG = 1;
            pressureGroup = RDPH::caluculatePG(divingTimeFor12, 26, divingTime);
            break;
        case 14:
            listForPG = 2;
            pressureGroup = RDPH::caluculatePG(divingTimeFor14, 25, divingTime);
            break;
        case 16:
            listForPG = 3;
            pressureGroup = RDPH::caluculatePG(divingTimeFor16, 24, divingTime);
        break;
        case 18:
            listForPG = 4;
            pressureGroup = RDPH::caluculatePG(divingTimeFor18, 23, divingTime);
            break;
        case 20:
            listForPG = 5;
            pressureGroup = RDPH::caluculatePG(divingTimeFor20, 21, divingTime);
            break;
        case 22:
            listForPG = 6;
            pressureGroup = RDPH::caluculatePG(divingTimeFor22, 19, divingTime);
            break;
        case 25:
            listForPG = 7;
            pressureGroup = RDPH::caluculatePG(divingTimeFor25, 17, divingTime);
            break;
        case 30:
            listForPG = 8;
            pressureGroup = RDPH::caluculatePG(divingTimeFor30, 14, divingTime);
            break;
        case 35:
            listForPG = 9;
            pressureGroup = RDPH::caluculatePG(divingTimeFor35, 11, divingTime);
            break;
        case 40:
            listForPG  = 10;
            pressureGroup = RDPH::caluculatePG(divingTimeFor40, 7, divingTime);
            break;
        case 42:
            listForPG = 11;
            pressureGroup = RDPH::caluculatePG(divingTimeFor42, 6, divingTime);
            break;
        default:
            std::cout << "I cannot find the deapth" << std::endl;
            break;
    }
    if (pressureGroup == "") {
        std::cout << "You cannot excced the NDL: " << NDL[listForPG] << std::endl;
        exit(6);
    }
    
    return pressureGroup;
}

std::string RDPH::caluculatePG(int list[], int length, int divingTime)
{
    std::string letter;
    int i = 0;

    if ((list[0] == 5 && list[1] == 5 ) || (list[0] == 4 && list[1] == 4)) {
        letter = RDPH::PG[1];
        return letter;
    }

    if (list[3] == 8){
        letter = RDPH::PG[4];
        return letter;
    }
    if (list[2] == 6){
        letter = RDPH::PG[3];
        return letter;
    }
    if (list[1] == 4){
        letter = RDPH::PG[2];
        return letter;
    }
    
    if (list[0] >= divingTime) {
        letter = RDPH::PG[0];
        return letter;
    }
    while (i < length) {
        if (list[i] < divingTime && list[i+1] >= divingTime) {
                letter = RDPH::PG[i+1];
                return letter;
        } else
        {
        }
        
        i = i+1;
    }
    
    return "";
}

std::string RDPH::searchPGMultiple(std::string pressureGroup, int surfaceInterval)
{
std::string returnValue;
    if (pressureGroup == "A") {
        returnValue = "A";
    }
    if (pressureGroup == "B") {
        returnValue = caluculatePGMultiple(surfaceIntervalForB, 2, surfaceInterval);
    }
    if (pressureGroup == "C") {
        returnValue = caluculatePGMultiple(surfaceIntervalForC, 3, surfaceInterval);
    }
    if (pressureGroup == "D") {
        returnValue = caluculatePGMultiple(surfaceIntervalForD, 4, surfaceInterval);
    }
    if (pressureGroup == "E") {
         returnValue = caluculatePGMultiple(surfaceIntervalForE, 5, surfaceInterval);
    }
    if (pressureGroup == "F") {
         returnValue = caluculatePGMultiple(surfaceIntervalForF, 6, surfaceInterval);
    }
    if (pressureGroup == "G") {
         returnValue = caluculatePGMultiple(surfaceIntervalForG, 7, surfaceInterval);
    }
    if (pressureGroup == "H") {
         returnValue = caluculatePGMultiple(surfaceIntervalForH, 8, surfaceInterval);
    }
    if (pressureGroup == "I") {
         returnValue = caluculatePGMultiple(surfaceIntervalForI, 9, surfaceInterval);
    }
    if (pressureGroup == "J") {
         returnValue = caluculatePGMultiple(surfaceIntervalForJ, 10, surfaceInterval);
    }
    if (pressureGroup == "K") {
         returnValue = caluculatePGMultiple(surfaceIntervalForK, 11, surfaceInterval);
    }
    if (pressureGroup == "L") {
         returnValue = caluculatePGMultiple(surfaceIntervalForL, 12, surfaceInterval);
    }
    if (pressureGroup == "M") {
         returnValue = caluculatePGMultiple(surfaceIntervalForM, 13, surfaceInterval);
    }
    if (pressureGroup == "N") {
         returnValue = caluculatePGMultiple(surfaceIntervalForN, 14, surfaceInterval);
    }
    if (pressureGroup == "O") {
         returnValue = caluculatePGMultiple(surfaceIntervalForO, 15, surfaceInterval);
    }
    if (pressureGroup == "P") {
         returnValue = caluculatePGMultiple(surfaceIntervalForP, 16, surfaceInterval);
    }
    if (pressureGroup == "Q") {
         returnValue = caluculatePGMultiple(surfaceIntervalForQ, 17, surfaceInterval);
    }
    if (pressureGroup == "R") {
         returnValue = caluculatePGMultiple(surfaceIntervalForR, 18, surfaceInterval);
    }
    if (pressureGroup == "S") {
         returnValue = caluculatePGMultiple(surfaceIntervalForS, 19, surfaceInterval);
    }
    if (pressureGroup == "T") {
         returnValue = caluculatePGMultiple(surfaceIntervalForT, 20, surfaceInterval);
    }
    if (pressureGroup == "U") {
         returnValue = caluculatePGMultiple(surfaceIntervalForU, 21, surfaceInterval);
    }
    if (pressureGroup == "V") {
         returnValue = caluculatePGMultiple(surfaceIntervalForV, 22, surfaceInterval);
    }
    if (pressureGroup == "W") {
         returnValue = caluculatePGMultiple(surfaceIntervalForW, 23, surfaceInterval);
    }
    if (pressureGroup == "X") {
         returnValue = caluculatePGMultiple(surfaceIntervalForX, 24, surfaceInterval);
    }
    if (pressureGroup == "Y") {
         returnValue = caluculatePGMultiple(surfaceIntervalForY, 25, surfaceInterval);
    }
    if (pressureGroup == "Z") {
         returnValue = caluculatePGMultiple(surfaceIntervalForZ, 26, surfaceInterval);
    }
    return returnValue;
}



std::string RDPH::caluculatePGMultiple(int list[], int length, int surfaceInterval)
{
    std::string letter = RDPH::PG[length-1];
        int i = 0;
    if (surfaceInterval >= list[0]) {
        letter = "A";
        return letter;
    }
        while (i < length) {
            if (surfaceInterval <= list[i] && surfaceInterval > list[i+1]) {
                letter = RDPH::PG[i];
                return letter;
            } else
            {
                
            }
            i = i+1;
        }
        return letter;
}

int RDPH::searchNDL(int deapthInput, std::string pressureGroup)
{
    int convert =0;
    int ndl = 0;
    
    convert = RDPH::convert(pressureGroup);
    if (deapthInput > 42) {
        std::cout << "You cannot dive more than 42m for the secontime or more." << std::endl;
        exit(7);
    }
    switch (deapthInput) {
        case 10:
            ndl = adujustedNDLfor10[convert];
            break;
        case 12:
            ndl = adujustedNDLfor12[convert];
            break;
        case 14:
            ndl = adujustedNDLfor14[convert];
            break;
        case 16:
            ndl = adujustedNDLfor16[convert];
        break;
        case 18:
            ndl = adujustedNDLfor18[convert];
            break;
        case 20:
            ndl = adujustedNDLfor20[convert];
            break;
        case 22:
            ndl = adujustedNDLfor22[convert];
            break;
        case 25:
            ndl = adujustedNDLfor25[convert];
            break;
        case 30:
            ndl = adujustedNDLfor30[convert];
            break;
        case 35:
            ndl = adujustedNDLfor35[convert];
            break;
        case 40:
            ndl = adujustedNDLfor40[convert];
            break;

        default:
            std::cout << "I cannot find the deapth" << std::endl;
            break;
    }
    return ndl;
}

int RDPH::convert(std::string pressureGroup)
{
    int convert=0;
    if (pressureGroup == "A") {
        convert = 0;
    }
    if (pressureGroup == "B") {
        convert = 1;
    }
    if (pressureGroup == "C") {
        convert = 2;
    }
    if (pressureGroup == "D") {
        convert = 3;
    }
    if (pressureGroup == "E") {
         convert = 4;
    }
    if (pressureGroup == "F") {
         convert = 5;
    }
    if (pressureGroup == "G") {
         convert = 6;
    }
    if (pressureGroup == "H") {
         convert = 7;
    }
    if (pressureGroup == "I") {
         convert = 8;
    }
    if (pressureGroup == "J") {
         convert = 9;
    }
    if (pressureGroup == "K") {
         convert = 10;
    }
    if (pressureGroup == "L") {
         convert = 11;
    }
    if (pressureGroup == "M") {
         convert = 12;
    }
    if (pressureGroup == "N") {
         convert = 13;
    }
    if (pressureGroup == "O") {
         convert = 14;
    }
    if (pressureGroup == "P") {
         convert = 15;
    }
    if (pressureGroup == "Q") {
         convert = 16;
    }
    if (pressureGroup == "R") {
         convert = 17;
    }
    if (pressureGroup == "S") {
         convert = 18;
    }
    if (pressureGroup == "T") {
         convert = 19;
    }
    if (pressureGroup == "U") {
         convert = 20;
    }
    if (pressureGroup == "V") {
         convert = 21;
    }
    if (pressureGroup == "W") {
         convert = 22;
    }
    if (pressureGroup == "X") {
         convert = 23;
    }
    if (pressureGroup == "Y") {
         convert = 24;
    }
    if (pressureGroup == "Z") {
         convert = 25;
    }
    return convert;
}


int RDPH::checkDeapthForSecond(std::string pressureGroup, int divingTimeForSecond)
{
    int pressureGrourpInt = 0;
    pressureGrourpInt = RDPH::convert(pressureGroup);
    if (divingTimeForSecond >= adujustedNDLfor10[pressureGrourpInt] ) {
        return 10;
    }
    if (adujustedNDLfor10[pressureGrourpInt] > divingTimeForSecond && divingTimeForSecond >= adujustedNDLfor12[pressureGrourpInt] ) {
        return 12;
    }
    if (adujustedNDLfor12[pressureGrourpInt] > divingTimeForSecond && divingTimeForSecond >= adujustedNDLfor14[pressureGrourpInt] ) {
        return 14;
    }
    if (adujustedNDLfor14[pressureGrourpInt] > divingTimeForSecond && divingTimeForSecond >= adujustedNDLfor16[pressureGrourpInt] ) {
        return 16;
    }
    if (adujustedNDLfor16[pressureGrourpInt] > divingTimeForSecond && divingTimeForSecond >= adujustedNDLfor18[pressureGrourpInt] ) {
        return 18;
    }
    if (adujustedNDLfor18[pressureGrourpInt] > divingTimeForSecond && divingTimeForSecond >= adujustedNDLfor20[pressureGrourpInt] ) {
        return 20;
    }
    if (adujustedNDLfor20[pressureGrourpInt] > divingTimeForSecond && divingTimeForSecond >= adujustedNDLfor22[pressureGrourpInt] ) {
        return 22;
    }
    if (adujustedNDLfor22[pressureGrourpInt] > divingTimeForSecond && divingTimeForSecond >= adujustedNDLfor25[pressureGrourpInt] ) {
        return 25;
    }
    if (adujustedNDLfor25[pressureGrourpInt] > divingTimeForSecond && divingTimeForSecond >= adujustedNDLfor30[pressureGrourpInt] ) {
        return 30;
    }
    if (adujustedNDLfor30[pressureGrourpInt] > divingTimeForSecond && divingTimeForSecond >= adujustedNDLfor35[pressureGrourpInt] ) {
        return 35;
    }
    if (adujustedNDLfor35[pressureGrourpInt] > divingTimeForSecond) {
        return 40;
    }
    return 0;
}

int RDPH::checkTBT(int deapthInput, int divingTime)
{
    int TBT =0, temp;
    std::string pressureGroup;
    switch (deapthInput) {
        case 10:
            pressureGroup = caluculatePG(divingTimeFor10, 26, divingTime);
            temp = convert(pressureGroup);
            TBT = divingTimeFor10[temp] + adujustedNDLfor10[temp];
            if (adujustedNDLfor10[temp] == 0) {
                TBT = -1;
            }
            break;
        case 12:
            pressureGroup = caluculatePG(divingTimeFor12, 26, divingTime);
            temp = convert(pressureGroup);
            TBT = divingTimeFor12[temp] + adujustedNDLfor12[temp];
            if (adujustedNDLfor12[temp] == 0) {
                TBT = -1;
            }
            break;
        case 14:
            pressureGroup = caluculatePG(divingTimeFor14, 25, divingTime);
            temp = convert(pressureGroup);
            TBT = divingTimeFor14[temp] + adujustedNDLfor14[temp];
            if (adujustedNDLfor14[temp] == 0) {
                TBT = -1;
            }
            break;
        case 16:
            pressureGroup = caluculatePG(divingTimeFor16, 24, divingTime);
            temp = convert(pressureGroup);
            TBT = divingTimeFor16[temp] + adujustedNDLfor16[temp];
            if (adujustedNDLfor16[temp] == 0) {
                TBT = -1;
            }
            break;
        case 18:
            pressureGroup = caluculatePG(divingTimeFor18, 23, divingTime);
            temp = convert(pressureGroup);
            TBT = divingTimeFor18[temp] + adujustedNDLfor18[temp];
            if (adujustedNDLfor18[temp] == 0) {
                TBT = -1;
            }
            break;
        case 20:
            pressureGroup = caluculatePG(divingTimeFor20, 21, divingTime);
            temp = convert(pressureGroup);
            TBT = divingTimeFor20[temp] + adujustedNDLfor20[temp];
            if (adujustedNDLfor20[temp] == 0) {
                TBT = -1;
            }
            break;
        case 22:
            pressureGroup = caluculatePG(divingTimeFor22, 19, divingTime);
            temp = convert(pressureGroup);
            TBT = divingTimeFor22[temp] + adujustedNDLfor22[temp];
            if (adujustedNDLfor22[temp] == 0) {
                TBT = -1;
            }
            break;
        case 25:
            pressureGroup = caluculatePG(divingTimeFor25, 17, divingTime);
            temp = convert(pressureGroup);
            TBT = divingTimeFor25[temp] + adujustedNDLfor25[temp];
            if (adujustedNDLfor25[temp] == 0) {
                TBT = -1;
            }
        case 30:
            pressureGroup = caluculatePG(divingTimeFor30, 14, divingTime);
            temp = convert(pressureGroup);
            TBT = divingTimeFor30[temp] + adujustedNDLfor30[temp];
            if (adujustedNDLfor30[temp] == 0) {
                TBT = -1;
            }
            break;
        case 35:
            pressureGroup = caluculatePG(divingTimeFor35, 11, divingTime);
            temp = convert(pressureGroup);
            TBT = divingTimeFor35[temp] + adujustedNDLfor35[temp];
            if (adujustedNDLfor35[temp] == 0) {
                TBT = -1;
            }
            break;
        case 40:
            pressureGroup = caluculatePG(divingTimeFor40, 7, divingTime);
            temp = convert(pressureGroup);
            TBT = divingTimeFor40[temp] + adujustedNDLfor40[temp];
            if (adujustedNDLfor40[temp] == 0) {
                TBT = -1;
            }
            break;
        default:
            std::cout << "I cannot find the deapth" << std::endl;
            break;
    }
    
    return TBT;
}
