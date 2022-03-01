//
//  RDPHeader.hpp
//  comp252Project
//
//  Created by Wataru Oshima on 2020/05/10.
//  Copyright © 2020 Wataru Oshima. All rights reserved.
//

#ifndef RDPHeader_hpp
#define RDPHeader_hpp

#include <stdio.h>
#include <string>
//#include <iostream>


class RDPH{
public:
    int searchNDL(int deapthInput);
    void initializeNode();
    void println();
    std::string searchPG(int deapthInput, int divingTime);
    std::string caluculatePG(int list[], int length, int divingTime);
    int searchNDL(int deapthInput, std::string pressureGroup);
    std::string searchPGMultiple(std::string pressureGroup, int surfaceInterval);
    std::string caluculatePGMultiple(int list[], int length, int surfaceInterval);
    int convert(std::string pressureGroup);
    int checkDeapthForSecond(std::string pressureGroup, int divingTimeForSecond);
    int checkTBT(int deapthInput, int divingTime);
private:
    int deapth[12] = {10, 12, 14, 16, 18, 20, 22, 25, 30, 35, 40, 42};
    int length = 12;
    std::string PG[26] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","P","Q","R","S","T","U","V","W","X", "Y", "Z"};
    int NDL[12] = {219, 147, 98, 72, 56, 45, 37, 29, 20, 14, 9, 9};
    int divingTimeFor10[26] = {10,20,26,30,34,37,41,45,50,54,59,64,70,75,82,88,95,104,112,122,133,145,160,178,199,219};
    int divingTimeFor12[26] = {9,17,23,26,29,32,35,38,42,45,49,53,57,62,66,71,76,82,88,94,101,108,116,125,134,147};
    int divingTimeFor14[25] = {8,15,19,22,24,27,29,32,35,37,40,43,47,50,53,57,61,64,68,73,77,82,87,92,98};
    int divingTimeFor16[24] = {7,13,17,19,21,23,25,27,29,32,34,37,39,42,45,48,50,53,56,60,63,67,70,72};
    int divingTimeFor18[23] = {6,11,15,16,18,20,22,24,26,28,30,32,34,36,39,41,43,46,48,51,53,55,56};
    int divingTimeFor20[21] = {6,10,13,15,16,18,19,21,23,25,26,28,30,32,34,36,38,40,42,44,45};
    int divingTimeFor22[19] = {5,9,12,13,15,16,18,19,21,22,24,25,27,29,30,32,34,36,37};
    int divingTimeFor25[17] = {4,8,10,11,13,14,15,17,18,19,21,22,23,25,26,28,29};
    int divingTimeFor30[14] = {3,6,8,9,10,11,12,13,14,15,16,17,19,20};
    int divingTimeFor35[11] = {3,5,7,8,8,9,10,11,12,13,14};
    int divingTimeFor40[7] = {5,5,6,6,7,8,9};
    int divingTimeFor42[6] = {4,4,4,6,7,8};
    
    int surfaceIntervalForA[1] ={3};
    int surfaceIntervalForB[2] ={228,47};
    int surfaceIntervalForC[3] ={250,69,21};
    int surfaceIntervalForD[4] ={259,78,30,8};
    int surfaceIntervalForE[5] ={268,87,38,16,7};
    int surfaceIntervalForF[6] ={275,94,46,24,15,7};
    int surfaceIntervalForG[7] ={282,101,53,31,22,13,6};
    int surfaceIntervalForH[8] ={288,107,59,37,28,20,12,5};
    int surfaceIntervalForI[9] ={294,113,65,43,34,26,18,11,5};
    int surfaceIntervalForJ[10] ={300,119,71,49,40,31,24,17,11,5};
    int surfaceIntervalForK[11] ={305,124,76,54,45,37,29,22,16,10,4};
    int surfaceIntervalForL[12] ={310,129,81,59,50,42,34,27,21,15,9,4};
    int surfaceIntervalForM[13] ={315,134,85,64,55,46,39,32,25,19,14,9,4};
    int surfaceIntervalForN[14] ={319,138,90,68,59,51,43,36,30,24,18,13,8,3};
    int surfaceIntervalForO[15] ={324,143,94,72,63,55,47,41,34,28,23,17,12,8,3};
    int surfaceIntervalForP[16] ={328,147,98,76,67,59,51,45,38,32,27,21,16,12,7,3};
    int surfaceIntervalForQ[17] ={331,150,102,80,71,63,55,48,42,36,30,25,20,16,11,7,3};
    int surfaceIntervalForR[18] ={335,154,106,84,75,67,59,52,46,40,34,29,24,19,15,11,7,3};
    int surfaceIntervalForS[19] ={339,158,109,87,78,70,63,56,49,43,38,32,27,23,18,14,10,6,3};
    int surfaceIntervalForT[20] ={342,161,113,91,82,73,66,59,52,47,41,36,31,26,22,17,13,10,6,2};
    int surfaceIntervalForU[21] ={345,164,116,94,85,67,69,62,56,50,44,39,34,29,25,21,17,13,9,6,2};
    int surfaceIntervalForV[22] ={348,167,119,97,88,80,72,65,59,53,47,42,37,33,28,24,20,16,12,9,5,2};
    int surfaceIntervalForW[23] ={351,170,122,100,91,83,75,68,62,56,50,45,40,36,31,27,23,19,15,12,8,5,2};
    int surfaceIntervalForX[24] ={354,173,125,103,94,86,78,71,65,59,53,48,43,39,34,30,26,22,18,15,11,8,5,2};
    int surfaceIntervalForY[25] ={357,176,128,106,97,89,81,74,68,62,56,51,46,41,37,33,29,25,21,18,14,11,8,5,2};
    int surfaceIntervalForZ[26] ={360,179,131,109,100,91,84,71,65,59,54,49,44,40,35,31,28,24,20,17,14,11,8,5,2};
    
    int adujustedNDLfor10[25] = {209,199,193,189,185,182,178,174,169,165,160,155,149,144,137,131,124,115,107,97,86,74,59,41,20};
    int adujustedNDLfor12[25] = {138,130,124,121,118,115,112,109,105,102,98,94,90,85,81,76,71,65,59,53,46,39,31,22,13};
    int adujustedNDLfor14[25] = {90,83,79,76,74,71,69,66,63,61,58,55,51,48,45,41,37,34,30,25,21,16,11,6};
    int adujustedNDLfor16[25] = {65,59,55,53,51,49,47,45,43,40,38,35,33,30,27,24,22,19,16,12,9,5,2};
    int adujustedNDLfor18[25] = {50,45,41,40,38,36,34,32,30,28,26,24,22,20,17,15,13,10,8,5,3};
    int adujustedNDLfor20[25] = {39,35,32,30,29,27,25,24,22,20,19,17,15,13,11,9,7,5,3};
    int adujustedNDLfor22[25] = {32,28,25,24,22,21,19,18,16,15,13,12,10,8,7,5,3};
    int adujustedNDLfor25[25] = {25,21,19,18,16,15,14,12,11,10,8,7,6,4,3};
    int adujustedNDLfor30[25] = {17,14,12,11,10,9,8,7,6,5,4,3};
    int adujustedNDLfor35[25] = {11,9,7,6,5,5,4,3};
    int adujustedNDLfor40[25] = {7,4};
};
    

#endif /* RDPHeader_hpp */
