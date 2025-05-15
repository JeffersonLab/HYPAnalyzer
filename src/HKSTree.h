//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Fri May  9 14:31:11 2025 by ROOT version 6.28/04
// from TTree tree/tree of HKS
// found on file: hks_sample.root
//////////////////////////////////////////////////////////

#ifndef HKSTree_h
#define HKSTree_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>

// Header file for the classes stored in the TTree if any.

class HKSTree {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain
   Int_t           fCurrent; //!current Tree number in a TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Int_t           evID;
   Double_t        KMom;
   Double_t        KTheta;
   Double_t        KPhi;
   Double_t        KXpt;
   Double_t        KYpt;
   Double_t        KXt;
   Double_t        KYt;
   Double_t        KZt;
   Double_t        KXSSi;
   Double_t        KYSSi;
   Double_t        KZSSi;
   Double_t        XpSSi;
   Double_t        YpSSi;
   Double_t        KXSSe;
   Double_t        KYSSe;
   Double_t        KZSSe;
   Double_t        XpSSe;
   Double_t        YpSSe;
   Double_t        KXPCSi;
   Double_t        KYPCSi;
   Double_t        KZPCSi;
   Double_t        XpPCSi;
   Double_t        YpPCSi;
   Double_t        KXPCSe;
   Double_t        KYPCSe;
   Double_t        KZPCSe;
   Double_t        XpPCSe;
   Double_t        YpPCSe;
   Double_t        KXQ1i;
   Double_t        KYQ1i;
   Double_t        KZQ1i;
   Double_t        KXpQ1i;
   Double_t        KYpQ1i;
   Int_t           KpidQ1i;
   Double_t        KXQ1e;
   Double_t        KYQ1e;
   Double_t        KZQ1e;
   Int_t           KpidQ1e;
   Double_t        KXQ2i;
   Double_t        KYQ2i;
   Double_t        KZQ2i;
   Int_t           KpidQ2i;
   Double_t        KXQ2e;
   Double_t        KYQ2e;
   Double_t        KZQ2e;
   Int_t           KpidQ2e;
   Double_t        KPDi;
   Double_t        KXDi;
   Double_t        KYDi;
   Double_t        KZDi;
   Int_t           KpidDi;
   Double_t        KPDe;
   Double_t        KXDe;
   Double_t        KYDe;
   Double_t        KZDe;
   Double_t        KXpDe;
   Double_t        KYpDe;
   Int_t           KpidDe;
   Double_t        KLFP1;
   Double_t        KPFP1;
   Double_t        KXFP1;
   Double_t        KYFP1;
   Double_t        KZFP1;
   Double_t        KXpFP1;
   Double_t        KYpFP1;
   Double_t        KXvFP1;
   Double_t        KYvFP1;
   Double_t        KZvFP1;
   Int_t           KpidFP1;
   Double_t        KLFP2;
   Double_t        KPFP2;
   Double_t        KXFP2;
   Double_t        KYFP2;
   Double_t        KZFP2;
   Double_t        KXpFP2;
   Double_t        KYpFP2;
   Double_t        KXvFP2;
   Double_t        KYvFP2;
   Double_t        KZvFP2;
   Int_t           KpidFP2;
   Double_t        KLFP3;
   Double_t        KPFP3;
   Double_t        KXFP3;
   Double_t        KYFP3;
   Double_t        KZFP3;
   Double_t        KXpFP3;
   Double_t        KYpFP3;
   Double_t        KXvFP3;
   Double_t        KYvFP3;
   Double_t        KZvFP3;
   Int_t           KpidFP3;
   Double_t        KLFP4;
   Double_t        KPFP4;
   Double_t        KXFP4;
   Double_t        KYFP4;
   Double_t        KZFP4;
   Double_t        KXpFP4;
   Double_t        KYpFP4;
   Double_t        KXvFP4;
   Double_t        KYvFP4;
   Double_t        KZvFP4;
   Int_t           KpidFP4;
   Double_t        KLFP5;
   Double_t        KPFP5;
   Double_t        KXFP5;
   Double_t        KYFP5;
   Double_t        KZFP5;
   Double_t        KXpFP5;
   Double_t        KYpFP5;
   Double_t        KXvFP5;
   Double_t        KYvFP5;
   Double_t        KZvFP5;
   Int_t           KpidFP5;
   Double_t        KLFP6;
   Double_t        KPFP6;
   Double_t        KXFP6;
   Double_t        KYFP6;
   Double_t        KZFP6;
   Double_t        KXpFP6;
   Double_t        KYpFP6;
   Double_t        KXvFP6;
   Double_t        KYvFP6;
   Double_t        KZvFP6;
   Int_t           KpidFP6;
   Int_t           WC1pid;
   Int_t           WC2pid;
   Double_t        XWC101;
   Double_t        YWC101;
   Double_t        ZWC101;
   Double_t        AWC101;
   Double_t        TWC101;
   Double_t        XWC102;
   Double_t        YWC102;
   Double_t        ZWC102;
   Double_t        AWC102;
   Double_t        TWC102;
   Double_t        XWC103;
   Double_t        YWC103;
   Double_t        ZWC103;
   Double_t        AWC103;
   Double_t        TWC103;
   Double_t        XWC104;
   Double_t        YWC104;
   Double_t        ZWC104;
   Double_t        AWC104;
   Double_t        TWC104;
   Double_t        XWC105;
   Double_t        YWC105;
   Double_t        ZWC105;
   Double_t        AWC105;
   Double_t        TWC105;
   Double_t        XWC106;
   Double_t        YWC106;
   Double_t        ZWC106;
   Double_t        AWC106;
   Double_t        TWC106;
   Double_t        XWC107;
   Double_t        YWC107;
   Double_t        ZWC107;
   Double_t        AWC107;
   Double_t        TWC107;
   Double_t        XWC108;
   Double_t        YWC108;
   Double_t        ZWC108;
   Double_t        AWC108;
   Double_t        TWC108;
   Double_t        XWC109;
   Double_t        YWC109;
   Double_t        ZWC109;
   Double_t        AWC109;
   Double_t        TWC109;
   Double_t        XWC110;
   Double_t        YWC110;
   Double_t        ZWC110;
   Double_t        AWC110;
   Double_t        TWC110;
   Double_t        XWC111;
   Double_t        YWC111;
   Double_t        ZWC111;
   Double_t        AWC111;
   Double_t        TWC111;
   Double_t        XWC112;
   Double_t        YWC112;
   Double_t        ZWC112;
   Double_t        AWC112;
   Double_t        TWC112;
   Double_t        XWC201;
   Double_t        YWC201;
   Double_t        ZWC201;
   Double_t        AWC201;
   Double_t        TWC201;
   Double_t        XWC202;
   Double_t        YWC202;
   Double_t        ZWC202;
   Double_t        AWC202;
   Double_t        TWC202;
   Double_t        XWC203;
   Double_t        YWC203;
   Double_t        ZWC203;
   Double_t        AWC203;
   Double_t        TWC203;
   Double_t        XWC204;
   Double_t        YWC204;
   Double_t        ZWC204;
   Double_t        AWC204;
   Double_t        TWC204;
   Double_t        XWC205;
   Double_t        YWC205;
   Double_t        ZWC205;
   Double_t        AWC205;
   Double_t        TWC205;
   Double_t        XWC206;
   Double_t        YWC206;
   Double_t        ZWC206;
   Double_t        AWC206;
   Double_t        TWC206;
   Double_t        XWC207;
   Double_t        YWC207;
   Double_t        ZWC207;
   Double_t        AWC207;
   Double_t        TWC207;
   Double_t        XWC208;
   Double_t        YWC208;
   Double_t        ZWC208;
   Double_t        AWC208;
   Double_t        TWC208;
   Double_t        XWC209;
   Double_t        YWC209;
   Double_t        ZWC209;
   Double_t        AWC209;
   Double_t        TWC209;
   Double_t        XWC210;
   Double_t        YWC210;
   Double_t        ZWC210;
   Double_t        AWC210;
   Double_t        TWC210;
   Double_t        XWC211;
   Double_t        YWC211;
   Double_t        ZWC211;
   Double_t        AWC211;
   Double_t        TWC211;
   Double_t        XWC212;
   Double_t        YWC212;
   Double_t        ZWC212;
   Double_t        AWC212;
   Double_t        TWC212;
   Int_t           AC1pid;
   Int_t           AC2pid;
   Int_t           AC3pid;
   Double_t        XAC101;
   Double_t        YAC101;
   Double_t        AAC101;
   Double_t        TAC101;
   Double_t        XAC102;
   Double_t        YAC102;
   Double_t        AAC102;
   Double_t        TAC102;
   Double_t        XAC103;
   Double_t        YAC103;
   Double_t        AAC103;
   Double_t        TAC103;
   Double_t        XAC104;
   Double_t        YAC104;
   Double_t        AAC104;
   Double_t        TAC104;
   Double_t        XAC105;
   Double_t        YAC105;
   Double_t        AAC105;
   Double_t        TAC105;
   Double_t        XAC106;
   Double_t        YAC106;
   Double_t        AAC106;
   Double_t        TAC106;
   Double_t        XAC107;
   Double_t        YAC107;
   Double_t        AAC107;
   Double_t        TAC107;
   Double_t        XAC201;
   Double_t        YAC201;
   Double_t        AAC201;
   Double_t        TAC201;
   Double_t        XAC202;
   Double_t        YAC202;
   Double_t        AAC202;
   Double_t        TAC202;
   Double_t        XAC203;
   Double_t        YAC203;
   Double_t        AAC203;
   Double_t        TAC203;
   Double_t        XAC204;
   Double_t        YAC204;
   Double_t        AAC204;
   Double_t        TAC204;
   Double_t        XAC205;
   Double_t        YAC205;
   Double_t        AAC205;
   Double_t        TAC205;
   Double_t        XAC206;
   Double_t        YAC206;
   Double_t        AAC206;
   Double_t        TAC206;
   Double_t        XAC207;
   Double_t        YAC207;
   Double_t        AAC207;
   Double_t        TAC207;
   Double_t        XAC301;
   Double_t        YAC301;
   Double_t        AAC301;
   Double_t        TAC301;
   Double_t        XAC302;
   Double_t        YAC302;
   Double_t        AAC302;
   Double_t        TAC302;
   Double_t        XAC303;
   Double_t        YAC303;
   Double_t        AAC303;
   Double_t        TAC303;
   Double_t        XAC304;
   Double_t        YAC304;
   Double_t        AAC304;
   Double_t        TAC304;
   Double_t        XAC305;
   Double_t        YAC305;
   Double_t        AAC305;
   Double_t        TAC305;
   Double_t        XAC306;
   Double_t        YAC306;
   Double_t        AAC306;
   Double_t        TAC306;
   Double_t        XAC307;
   Double_t        YAC307;
   Double_t        AAC307;
   Double_t        TAC307;
   Int_t           TOF1Xpid;
   Int_t           TOF1Ypid;
   Int_t           TOF2Xpid;
   Double_t        TTOF1X;
   Double_t        TTOF1Y;
   Double_t        TTOF2X;
   Double_t        LTOF1X;
   Double_t        LTOF1Y;
   Double_t        LTOF2X;
   Double_t        XTOF101;
   Double_t        YTOF101;
   Double_t        ATOF101;
   Double_t        TTOF101;
   Double_t        XTOF102;
   Double_t        YTOF102;
   Double_t        ATOF102;
   Double_t        TTOF102;
   Double_t        XTOF103;
   Double_t        YTOF103;
   Double_t        ATOF103;
   Double_t        TTOF103;
   Double_t        XTOF104;
   Double_t        YTOF104;
   Double_t        ATOF104;
   Double_t        TTOF104;
   Double_t        XTOF105;
   Double_t        YTOF105;
   Double_t        ATOF105;
   Double_t        TTOF105;
   Double_t        XTOF106;
   Double_t        YTOF106;
   Double_t        ATOF106;
   Double_t        TTOF106;
   Double_t        XTOF107;
   Double_t        YTOF107;
   Double_t        ATOF107;
   Double_t        TTOF107;
   Double_t        XTOF108;
   Double_t        YTOF108;
   Double_t        ATOF108;
   Double_t        TTOF108;
   Double_t        XTOF109;
   Double_t        YTOF109;
   Double_t        ATOF109;
   Double_t        TTOF109;
   Double_t        XTOF110;
   Double_t        YTOF110;
   Double_t        ATOF110;
   Double_t        TTOF110;
   Double_t        XTOF111;
   Double_t        YTOF111;
   Double_t        ATOF111;
   Double_t        TTOF111;
   Double_t        XTOF112;
   Double_t        YTOF112;
   Double_t        ATOF112;
   Double_t        TTOF112;
   Double_t        XTOF113;
   Double_t        YTOF113;
   Double_t        ATOF113;
   Double_t        TTOF113;
   Double_t        XTOF114;
   Double_t        YTOF114;
   Double_t        ATOF114;
   Double_t        TTOF114;
   Double_t        XTOF115;
   Double_t        YTOF115;
   Double_t        ATOF115;
   Double_t        TTOF115;
   Double_t        XTOF116;
   Double_t        YTOF116;
   Double_t        ATOF116;
   Double_t        TTOF116;
   Double_t        XTOF117;
   Double_t        YTOF117;
   Double_t        ATOF117;
   Double_t        TTOF117;
   Double_t        XTOF118;
   Double_t        YTOF118;
   Double_t        ATOF118;
   Double_t        TTOF118;
   Double_t        XTOF201;
   Double_t        YTOF201;
   Double_t        ATOF201;
   Double_t        TTOF201;
   Double_t        XTOF202;
   Double_t        YTOF202;
   Double_t        ATOF202;
   Double_t        TTOF202;
   Double_t        XTOF203;
   Double_t        YTOF203;
   Double_t        ATOF203;
   Double_t        TTOF203;
   Double_t        XTOF204;
   Double_t        YTOF204;
   Double_t        ATOF204;
   Double_t        TTOF204;
   Double_t        XTOF205;
   Double_t        YTOF205;
   Double_t        ATOF205;
   Double_t        TTOF205;
   Double_t        XTOF206;
   Double_t        YTOF206;
   Double_t        ATOF206;
   Double_t        TTOF206;
   Double_t        XTOF207;
   Double_t        YTOF207;
   Double_t        ATOF207;
   Double_t        TTOF207;
   Double_t        XTOF208;
   Double_t        YTOF208;
   Double_t        ATOF208;
   Double_t        TTOF208;
   Double_t        XTOF209;
   Double_t        YTOF209;
   Double_t        ATOF209;
   Double_t        TTOF209;
   Double_t        XTOF210;
   Double_t        YTOF210;
   Double_t        ATOF210;
   Double_t        TTOF210;
   Double_t        XTOF211;
   Double_t        YTOF211;
   Double_t        ATOF211;
   Double_t        TTOF211;
   Double_t        XTOF212;
   Double_t        YTOF212;
   Double_t        ATOF212;
   Double_t        TTOF212;
   Double_t        XTOF213;
   Double_t        YTOF213;
   Double_t        ATOF213;
   Double_t        TTOF213;
   Double_t        XTOF214;
   Double_t        YTOF214;
   Double_t        ATOF214;
   Double_t        TTOF214;
   Double_t        XTOF215;
   Double_t        YTOF215;
   Double_t        ATOF215;
   Double_t        TTOF215;
   Double_t        XTOF216;
   Double_t        YTOF216;
   Double_t        ATOF216;
   Double_t        TTOF216;
   Double_t        XTOF217;
   Double_t        YTOF217;
   Double_t        ATOF217;
   Double_t        TTOF217;
   Double_t        XTOF218;
   Double_t        YTOF218;
   Double_t        ATOF218;
   Double_t        TTOF218;
   Double_t        XTOF301;
   Double_t        YTOF301;
   Double_t        ATOF301;
   Double_t        TTOF301;
   Double_t        XTOF302;
   Double_t        YTOF302;
   Double_t        ATOF302;
   Double_t        TTOF302;
   Double_t        XTOF303;
   Double_t        YTOF303;
   Double_t        ATOF303;
   Double_t        TTOF303;
   Double_t        XTOF304;
   Double_t        YTOF304;
   Double_t        ATOF304;
   Double_t        TTOF304;
   Double_t        XTOF305;
   Double_t        YTOF305;
   Double_t        ATOF305;
   Double_t        TTOF305;
   Double_t        XTOF306;
   Double_t        YTOF306;
   Double_t        ATOF306;
   Double_t        TTOF306;
   Double_t        XTOF307;
   Double_t        YTOF307;
   Double_t        ATOF307;
   Double_t        TTOF307;
   Double_t        XTOF308;
   Double_t        YTOF308;
   Double_t        ATOF308;
   Double_t        TTOF308;
   Double_t        XTOF309;
   Double_t        YTOF309;
   Double_t        ATOF309;
   Double_t        TTOF309;
   Double_t        XTOF310;
   Double_t        YTOF310;
   Double_t        ATOF310;
   Double_t        TTOF310;
   Double_t        XTOF311;
   Double_t        YTOF311;
   Double_t        ATOF311;
   Double_t        TTOF311;
   Double_t        XTOF312;
   Double_t        YTOF312;
   Double_t        ATOF312;
   Double_t        TTOF312;
   Double_t        XTOF313;
   Double_t        YTOF313;
   Double_t        ATOF313;
   Double_t        TTOF313;
   Double_t        XTOF314;
   Double_t        YTOF314;
   Double_t        ATOF314;
   Double_t        TTOF314;
   Double_t        XTOF315;
   Double_t        YTOF315;
   Double_t        ATOF315;
   Double_t        TTOF315;
   Double_t        XTOF316;
   Double_t        YTOF316;
   Double_t        ATOF316;
   Double_t        TTOF316;
   Double_t        XTOF317;
   Double_t        YTOF317;
   Double_t        ATOF317;
   Double_t        TTOF317;
   Double_t        XTOF318;
   Double_t        YTOF318;
   Double_t        ATOF318;
   Double_t        TTOF318;
   Double_t        PKDC1;
   Double_t        XKDC1;
   Double_t        YKDC1;
   Double_t        ZKDC1;
   Double_t        XpKDC1;
   Double_t        YpKDC1;
   Double_t        PKDC2;
   Double_t        XKDC2;
   Double_t        YKDC2;
   Double_t        ZKDC2;
   Double_t        XpKDC2;
   Double_t        YpKDC2;
   Double_t        PKDC3;
   Double_t        XKDC3;
   Double_t        YKDC3;
   Double_t        ZKDC3;
   Double_t        XpKDC3;
   Double_t        YpKDC3;
   Double_t        PKDC4;
   Double_t        XKDC4;
   Double_t        YKDC4;
   Double_t        ZKDC4;
   Double_t        XpKDC4;
   Double_t        YpKDC4;
   Double_t        PKDC5;
   Double_t        XKDC5;
   Double_t        YKDC5;
   Double_t        ZKDC5;
   Double_t        XpKDC5;
   Double_t        YpKDC5;
   Double_t        PKDC6;
   Double_t        XKDC6;
   Double_t        YKDC6;
   Double_t        ZKDC6;
   Double_t        XpKDC6;
   Double_t        YpKDC6;
   Double_t        PKDC7;
   Double_t        XKDC7;
   Double_t        YKDC7;
   Double_t        ZKDC7;
   Double_t        XpKDC7;
   Double_t        YpKDC7;
   Double_t        PKDC8;
   Double_t        XKDC8;
   Double_t        YKDC8;
   Double_t        ZKDC8;
   Double_t        XpKDC8;
   Double_t        YpKDC8;
   Double_t        PKDC9;
   Double_t        XKDC9;
   Double_t        YKDC9;
   Double_t        ZKDC9;
   Double_t        XpKDC9;
   Double_t        YpKDC9;
   Double_t        PKDC10;
   Double_t        XKDC10;
   Double_t        YKDC10;
   Double_t        ZKDC10;
   Double_t        XpKDC10;
   Double_t        YpKDC10;
   Double_t        PKDC11;
   Double_t        XKDC11;
   Double_t        YKDC11;
   Double_t        ZKDC11;
   Double_t        XpKDC11;
   Double_t        YpKDC11;
   Double_t        PKDC12;
   Double_t        XKDC12;
   Double_t        YKDC12;
   Double_t        ZKDC12;
   Double_t        XpKDC12;
   Double_t        YpKDC12;
   Char_t          Trig;
   Char_t          VDTrig;
   Char_t          KDCTrig;
   Char_t          TOF1Trig;
   Char_t          TOF2Trig;
   Char_t          TOFTrig;
   Char_t          AC1Trig;
   Char_t          AC2Trig;
   Char_t          AC3Trig;
   Char_t          WC1Trig;
   Char_t          WC2Trig;

   // List of branches
   TBranch        *b_evID;   //!
   TBranch        *b_KMom;   //!
   TBranch        *b_KTheta;   //!
   TBranch        *b_KPhi;   //!
   TBranch        *b_KXpt;   //!
   TBranch        *b_KYpt;   //!
   TBranch        *b_KXt;   //!
   TBranch        *b_KYt;   //!
   TBranch        *b_KZt;   //!
   TBranch        *b_KXSSi;   //!
   TBranch        *b_KYSSi;   //!
   TBranch        *b_KZSSi;   //!
   TBranch        *b_XpSSi;   //!
   TBranch        *b_YpSSi;   //!
   TBranch        *b_KXSSe;   //!
   TBranch        *b_KYSSe;   //!
   TBranch        *b_KZSSe;   //!
   TBranch        *b_XpSSe;   //!
   TBranch        *b_YpSSe;   //!
   TBranch        *b_KXPCSi;   //!
   TBranch        *b_KYPCSi;   //!
   TBranch        *b_KZPCSi;   //!
   TBranch        *b_XpPCSi;   //!
   TBranch        *b_YpPCSi;   //!
   TBranch        *b_KXPCSe;   //!
   TBranch        *b_KYPCSe;   //!
   TBranch        *b_KZPCSe;   //!
   TBranch        *b_XpPCSe;   //!
   TBranch        *b_YpPCSe;   //!
   TBranch        *b_KXQ1i;   //!
   TBranch        *b_KYQ1i;   //!
   TBranch        *b_KZQ1i;   //!
   TBranch        *b_KXpQ1i;   //!
   TBranch        *b_KYpQ1i;   //!
   TBranch        *b_KpidQ1i;   //!
   TBranch        *b_KXQ1e;   //!
   TBranch        *b_KYQ1e;   //!
   TBranch        *b_KZQ1e;   //!
   TBranch        *b_KpidQ1e;   //!
   TBranch        *b_KXQ2i;   //!
   TBranch        *b_KYQ2i;   //!
   TBranch        *b_KZQ2i;   //!
   TBranch        *b_KpidQ2i;   //!
   TBranch        *b_KXQ2e;   //!
   TBranch        *b_KYQ2e;   //!
   TBranch        *b_KZQ2e;   //!
   TBranch        *b_KpidQ2e;   //!
   TBranch        *b_KPDi;   //!
   TBranch        *b_KXDi;   //!
   TBranch        *b_KYDi;   //!
   TBranch        *b_KZDi;   //!
   TBranch        *b_KpidDi;   //!
   TBranch        *b_KPDe;   //!
   TBranch        *b_KXDe;   //!
   TBranch        *b_KYDe;   //!
   TBranch        *b_KZDe;   //!
   TBranch        *b_KXpDe;   //!
   TBranch        *b_KYpDe;   //!
   TBranch        *b_KpidDe;   //!
   TBranch        *b_KLFP1;   //!
   TBranch        *b_KPFP1;   //!
   TBranch        *b_KXFP1;   //!
   TBranch        *b_KYFP1;   //!
   TBranch        *b_KZFP1;   //!
   TBranch        *b_KXpFP1;   //!
   TBranch        *b_KYpFP1;   //!
   TBranch        *b_KXvFP1;   //!
   TBranch        *b_KYvFP1;   //!
   TBranch        *b_KZvFP1;   //!
   TBranch        *b_KpidFP1;   //!
   TBranch        *b_KLFP2;   //!
   TBranch        *b_KPFP2;   //!
   TBranch        *b_KXFP2;   //!
   TBranch        *b_KYFP2;   //!
   TBranch        *b_KZFP2;   //!
   TBranch        *b_KXpFP2;   //!
   TBranch        *b_KYpFP2;   //!
   TBranch        *b_KXvFP2;   //!
   TBranch        *b_KYvFP2;   //!
   TBranch        *b_KZvFP2;   //!
   TBranch        *b_KpidFP2;   //!
   TBranch        *b_KLFP3;   //!
   TBranch        *b_KPFP3;   //!
   TBranch        *b_KXFP3;   //!
   TBranch        *b_KYFP3;   //!
   TBranch        *b_KZFP3;   //!
   TBranch        *b_KXpFP3;   //!
   TBranch        *b_KYpFP3;   //!
   TBranch        *b_KXvFP3;   //!
   TBranch        *b_KYvFP3;   //!
   TBranch        *b_KZvFP3;   //!
   TBranch        *b_KpidFP3;   //!
   TBranch        *b_KLFP4;   //!
   TBranch        *b_KPFP4;   //!
   TBranch        *b_KXFP4;   //!
   TBranch        *b_KYFP4;   //!
   TBranch        *b_KZFP4;   //!
   TBranch        *b_KXpFP4;   //!
   TBranch        *b_KYpFP4;   //!
   TBranch        *b_KXvFP4;   //!
   TBranch        *b_KYvFP4;   //!
   TBranch        *b_KZvFP4;   //!
   TBranch        *b_KpidFP4;   //!
   TBranch        *b_KLFP5;   //!
   TBranch        *b_KPFP5;   //!
   TBranch        *b_KXFP5;   //!
   TBranch        *b_KYFP5;   //!
   TBranch        *b_KZFP5;   //!
   TBranch        *b_KXpFP5;   //!
   TBranch        *b_KYpFP5;   //!
   TBranch        *b_KXvFP5;   //!
   TBranch        *b_KYvFP5;   //!
   TBranch        *b_KZvFP5;   //!
   TBranch        *b_KpidFP5;   //!
   TBranch        *b_KLFP6;   //!
   TBranch        *b_KPFP6;   //!
   TBranch        *b_KXFP6;   //!
   TBranch        *b_KYFP6;   //!
   TBranch        *b_KZFP6;   //!
   TBranch        *b_KXpFP6;   //!
   TBranch        *b_KYpFP6;   //!
   TBranch        *b_KXvFP6;   //!
   TBranch        *b_KYvFP6;   //!
   TBranch        *b_KZvFP6;   //!
   TBranch        *b_KpidFP6;   //!
   TBranch        *b_WC1pid;   //!
   TBranch        *b_WC2pid;   //!
   TBranch        *b_XWC101;   //!
   TBranch        *b_YWC101;   //!
   TBranch        *b_ZWC101;   //!
   TBranch        *b_AWC101;   //!
   TBranch        *b_TWC101;   //!
   TBranch        *b_XWC102;   //!
   TBranch        *b_YWC102;   //!
   TBranch        *b_ZWC102;   //!
   TBranch        *b_AWC102;   //!
   TBranch        *b_TWC102;   //!
   TBranch        *b_XWC103;   //!
   TBranch        *b_YWC103;   //!
   TBranch        *b_ZWC103;   //!
   TBranch        *b_AWC103;   //!
   TBranch        *b_TWC103;   //!
   TBranch        *b_XWC104;   //!
   TBranch        *b_YWC104;   //!
   TBranch        *b_ZWC104;   //!
   TBranch        *b_AWC104;   //!
   TBranch        *b_TWC104;   //!
   TBranch        *b_XWC105;   //!
   TBranch        *b_YWC105;   //!
   TBranch        *b_ZWC105;   //!
   TBranch        *b_AWC105;   //!
   TBranch        *b_TWC105;   //!
   TBranch        *b_XWC106;   //!
   TBranch        *b_YWC106;   //!
   TBranch        *b_ZWC106;   //!
   TBranch        *b_AWC106;   //!
   TBranch        *b_TWC106;   //!
   TBranch        *b_XWC107;   //!
   TBranch        *b_YWC107;   //!
   TBranch        *b_ZWC107;   //!
   TBranch        *b_AWC107;   //!
   TBranch        *b_TWC107;   //!
   TBranch        *b_XWC108;   //!
   TBranch        *b_YWC108;   //!
   TBranch        *b_ZWC108;   //!
   TBranch        *b_AWC108;   //!
   TBranch        *b_TWC108;   //!
   TBranch        *b_XWC109;   //!
   TBranch        *b_YWC109;   //!
   TBranch        *b_ZWC109;   //!
   TBranch        *b_AWC109;   //!
   TBranch        *b_TWC109;   //!
   TBranch        *b_XWC110;   //!
   TBranch        *b_YWC110;   //!
   TBranch        *b_ZWC110;   //!
   TBranch        *b_AWC110;   //!
   TBranch        *b_TWC110;   //!
   TBranch        *b_XWC111;   //!
   TBranch        *b_YWC111;   //!
   TBranch        *b_ZWC111;   //!
   TBranch        *b_AWC111;   //!
   TBranch        *b_TWC111;   //!
   TBranch        *b_XWC112;   //!
   TBranch        *b_YWC112;   //!
   TBranch        *b_ZWC112;   //!
   TBranch        *b_AWC112;   //!
   TBranch        *b_TWC112;   //!
   TBranch        *b_XWC201;   //!
   TBranch        *b_YWC201;   //!
   TBranch        *b_ZWC201;   //!
   TBranch        *b_AWC201;   //!
   TBranch        *b_TWC201;   //!
   TBranch        *b_XWC202;   //!
   TBranch        *b_YWC202;   //!
   TBranch        *b_ZWC202;   //!
   TBranch        *b_AWC202;   //!
   TBranch        *b_TWC202;   //!
   TBranch        *b_XWC203;   //!
   TBranch        *b_YWC203;   //!
   TBranch        *b_ZWC203;   //!
   TBranch        *b_AWC203;   //!
   TBranch        *b_TWC203;   //!
   TBranch        *b_XWC204;   //!
   TBranch        *b_YWC204;   //!
   TBranch        *b_ZWC204;   //!
   TBranch        *b_AWC204;   //!
   TBranch        *b_TWC204;   //!
   TBranch        *b_XWC205;   //!
   TBranch        *b_YWC205;   //!
   TBranch        *b_ZWC205;   //!
   TBranch        *b_AWC205;   //!
   TBranch        *b_TWC205;   //!
   TBranch        *b_XWC206;   //!
   TBranch        *b_YWC206;   //!
   TBranch        *b_ZWC206;   //!
   TBranch        *b_AWC206;   //!
   TBranch        *b_TWC206;   //!
   TBranch        *b_XWC207;   //!
   TBranch        *b_YWC207;   //!
   TBranch        *b_ZWC207;   //!
   TBranch        *b_AWC207;   //!
   TBranch        *b_TWC207;   //!
   TBranch        *b_XWC208;   //!
   TBranch        *b_YWC208;   //!
   TBranch        *b_ZWC208;   //!
   TBranch        *b_AWC208;   //!
   TBranch        *b_TWC208;   //!
   TBranch        *b_XWC209;   //!
   TBranch        *b_YWC209;   //!
   TBranch        *b_ZWC209;   //!
   TBranch        *b_AWC209;   //!
   TBranch        *b_TWC209;   //!
   TBranch        *b_XWC210;   //!
   TBranch        *b_YWC210;   //!
   TBranch        *b_ZWC210;   //!
   TBranch        *b_AWC210;   //!
   TBranch        *b_TWC210;   //!
   TBranch        *b_XWC211;   //!
   TBranch        *b_YWC211;   //!
   TBranch        *b_ZWC211;   //!
   TBranch        *b_AWC211;   //!
   TBranch        *b_TWC211;   //!
   TBranch        *b_XWC212;   //!
   TBranch        *b_YWC212;   //!
   TBranch        *b_ZWC212;   //!
   TBranch        *b_AWC212;   //!
   TBranch        *b_TWC212;   //!
   TBranch        *b_AC1pid;   //!
   TBranch        *b_AC2pid;   //!
   TBranch        *b_AC3pid;   //!
   TBranch        *b_XAC101;   //!
   TBranch        *b_YAC101;   //!
   TBranch        *b_AAC101;   //!
   TBranch        *b_TAC101;   //!
   TBranch        *b_XAC102;   //!
   TBranch        *b_YAC102;   //!
   TBranch        *b_AAC102;   //!
   TBranch        *b_TAC102;   //!
   TBranch        *b_XAC103;   //!
   TBranch        *b_YAC103;   //!
   TBranch        *b_AAC103;   //!
   TBranch        *b_TAC103;   //!
   TBranch        *b_XAC104;   //!
   TBranch        *b_YAC104;   //!
   TBranch        *b_AAC104;   //!
   TBranch        *b_TAC104;   //!
   TBranch        *b_XAC105;   //!
   TBranch        *b_YAC105;   //!
   TBranch        *b_AAC105;   //!
   TBranch        *b_TAC105;   //!
   TBranch        *b_XAC106;   //!
   TBranch        *b_YAC106;   //!
   TBranch        *b_AAC106;   //!
   TBranch        *b_TAC106;   //!
   TBranch        *b_XAC107;   //!
   TBranch        *b_YAC107;   //!
   TBranch        *b_AAC107;   //!
   TBranch        *b_TAC107;   //!
   TBranch        *b_XAC201;   //!
   TBranch        *b_YAC201;   //!
   TBranch        *b_AAC201;   //!
   TBranch        *b_TAC201;   //!
   TBranch        *b_XAC202;   //!
   TBranch        *b_YAC202;   //!
   TBranch        *b_AAC202;   //!
   TBranch        *b_TAC202;   //!
   TBranch        *b_XAC203;   //!
   TBranch        *b_YAC203;   //!
   TBranch        *b_AAC203;   //!
   TBranch        *b_TAC203;   //!
   TBranch        *b_XAC204;   //!
   TBranch        *b_YAC204;   //!
   TBranch        *b_AAC204;   //!
   TBranch        *b_TAC204;   //!
   TBranch        *b_XAC205;   //!
   TBranch        *b_YAC205;   //!
   TBranch        *b_AAC205;   //!
   TBranch        *b_TAC205;   //!
   TBranch        *b_XAC206;   //!
   TBranch        *b_YAC206;   //!
   TBranch        *b_AAC206;   //!
   TBranch        *b_TAC206;   //!
   TBranch        *b_XAC207;   //!
   TBranch        *b_YAC207;   //!
   TBranch        *b_AAC207;   //!
   TBranch        *b_TAC207;   //!
   TBranch        *b_XAC301;   //!
   TBranch        *b_YAC301;   //!
   TBranch        *b_AAC301;   //!
   TBranch        *b_TAC301;   //!
   TBranch        *b_XAC302;   //!
   TBranch        *b_YAC302;   //!
   TBranch        *b_AAC302;   //!
   TBranch        *b_TAC302;   //!
   TBranch        *b_XAC303;   //!
   TBranch        *b_YAC303;   //!
   TBranch        *b_AAC303;   //!
   TBranch        *b_TAC303;   //!
   TBranch        *b_XAC304;   //!
   TBranch        *b_YAC304;   //!
   TBranch        *b_AAC304;   //!
   TBranch        *b_TAC304;   //!
   TBranch        *b_XAC305;   //!
   TBranch        *b_YAC305;   //!
   TBranch        *b_AAC305;   //!
   TBranch        *b_TAC305;   //!
   TBranch        *b_XAC306;   //!
   TBranch        *b_YAC306;   //!
   TBranch        *b_AAC306;   //!
   TBranch        *b_TAC306;   //!
   TBranch        *b_XAC307;   //!
   TBranch        *b_YAC307;   //!
   TBranch        *b_AAC307;   //!
   TBranch        *b_TAC307;   //!
   TBranch        *b_TOF1Xpid;   //!
   TBranch        *b_TOF1Ypid;   //!
   TBranch        *b_TOF2Xpid;   //!
   TBranch        *b_TTOF1X;   //!
   TBranch        *b_TTOF1Y;   //!
   TBranch        *b_TTOF2X;   //!
   TBranch        *b_LTOF1X;   //!
   TBranch        *b_LTOF1Y;   //!
   TBranch        *b_LTOF2X;   //!
   TBranch        *b_XTOF101;   //!
   TBranch        *b_YTOF101;   //!
   TBranch        *b_ATOF101;   //!
   TBranch        *b_TTOF101;   //!
   TBranch        *b_XTOF102;   //!
   TBranch        *b_YTOF102;   //!
   TBranch        *b_ATOF102;   //!
   TBranch        *b_TTOF102;   //!
   TBranch        *b_XTOF103;   //!
   TBranch        *b_YTOF103;   //!
   TBranch        *b_ATOF103;   //!
   TBranch        *b_TTOF103;   //!
   TBranch        *b_XTOF104;   //!
   TBranch        *b_YTOF104;   //!
   TBranch        *b_ATOF104;   //!
   TBranch        *b_TTOF104;   //!
   TBranch        *b_XTOF105;   //!
   TBranch        *b_YTOF105;   //!
   TBranch        *b_ATOF105;   //!
   TBranch        *b_TTOF105;   //!
   TBranch        *b_XTOF106;   //!
   TBranch        *b_YTOF106;   //!
   TBranch        *b_ATOF106;   //!
   TBranch        *b_TTOF106;   //!
   TBranch        *b_XTOF107;   //!
   TBranch        *b_YTOF107;   //!
   TBranch        *b_ATOF107;   //!
   TBranch        *b_TTOF107;   //!
   TBranch        *b_XTOF108;   //!
   TBranch        *b_YTOF108;   //!
   TBranch        *b_ATOF108;   //!
   TBranch        *b_TTOF108;   //!
   TBranch        *b_XTOF109;   //!
   TBranch        *b_YTOF109;   //!
   TBranch        *b_ATOF109;   //!
   TBranch        *b_TTOF109;   //!
   TBranch        *b_XTOF110;   //!
   TBranch        *b_YTOF110;   //!
   TBranch        *b_ATOF110;   //!
   TBranch        *b_TTOF110;   //!
   TBranch        *b_XTOF111;   //!
   TBranch        *b_YTOF111;   //!
   TBranch        *b_ATOF111;   //!
   TBranch        *b_TTOF111;   //!
   TBranch        *b_XTOF112;   //!
   TBranch        *b_YTOF112;   //!
   TBranch        *b_ATOF112;   //!
   TBranch        *b_TTOF112;   //!
   TBranch        *b_XTOF113;   //!
   TBranch        *b_YTOF113;   //!
   TBranch        *b_ATOF113;   //!
   TBranch        *b_TTOF113;   //!
   TBranch        *b_XTOF114;   //!
   TBranch        *b_YTOF114;   //!
   TBranch        *b_ATOF114;   //!
   TBranch        *b_TTOF114;   //!
   TBranch        *b_XTOF115;   //!
   TBranch        *b_YTOF115;   //!
   TBranch        *b_ATOF115;   //!
   TBranch        *b_TTOF115;   //!
   TBranch        *b_XTOF116;   //!
   TBranch        *b_YTOF116;   //!
   TBranch        *b_ATOF116;   //!
   TBranch        *b_TTOF116;   //!
   TBranch        *b_XTOF117;   //!
   TBranch        *b_YTOF117;   //!
   TBranch        *b_ATOF117;   //!
   TBranch        *b_TTOF117;   //!
   TBranch        *b_XTOF118;   //!
   TBranch        *b_YTOF118;   //!
   TBranch        *b_ATOF118;   //!
   TBranch        *b_TTOF118;   //!
   TBranch        *b_XTOF201;   //!
   TBranch        *b_YTOF201;   //!
   TBranch        *b_ATOF201;   //!
   TBranch        *b_TTOF201;   //!
   TBranch        *b_XTOF202;   //!
   TBranch        *b_YTOF202;   //!
   TBranch        *b_ATOF202;   //!
   TBranch        *b_TTOF202;   //!
   TBranch        *b_XTOF203;   //!
   TBranch        *b_YTOF203;   //!
   TBranch        *b_ATOF203;   //!
   TBranch        *b_TTOF203;   //!
   TBranch        *b_XTOF204;   //!
   TBranch        *b_YTOF204;   //!
   TBranch        *b_ATOF204;   //!
   TBranch        *b_TTOF204;   //!
   TBranch        *b_XTOF205;   //!
   TBranch        *b_YTOF205;   //!
   TBranch        *b_ATOF205;   //!
   TBranch        *b_TTOF205;   //!
   TBranch        *b_XTOF206;   //!
   TBranch        *b_YTOF206;   //!
   TBranch        *b_ATOF206;   //!
   TBranch        *b_TTOF206;   //!
   TBranch        *b_XTOF207;   //!
   TBranch        *b_YTOF207;   //!
   TBranch        *b_ATOF207;   //!
   TBranch        *b_TTOF207;   //!
   TBranch        *b_XTOF208;   //!
   TBranch        *b_YTOF208;   //!
   TBranch        *b_ATOF208;   //!
   TBranch        *b_TTOF208;   //!
   TBranch        *b_XTOF209;   //!
   TBranch        *b_YTOF209;   //!
   TBranch        *b_ATOF209;   //!
   TBranch        *b_TTOF209;   //!
   TBranch        *b_XTOF210;   //!
   TBranch        *b_YTOF210;   //!
   TBranch        *b_ATOF210;   //!
   TBranch        *b_TTOF210;   //!
   TBranch        *b_XTOF211;   //!
   TBranch        *b_YTOF211;   //!
   TBranch        *b_ATOF211;   //!
   TBranch        *b_TTOF211;   //!
   TBranch        *b_XTOF212;   //!
   TBranch        *b_YTOF212;   //!
   TBranch        *b_ATOF212;   //!
   TBranch        *b_TTOF212;   //!
   TBranch        *b_XTOF213;   //!
   TBranch        *b_YTOF213;   //!
   TBranch        *b_ATOF213;   //!
   TBranch        *b_TTOF213;   //!
   TBranch        *b_XTOF214;   //!
   TBranch        *b_YTOF214;   //!
   TBranch        *b_ATOF214;   //!
   TBranch        *b_TTOF214;   //!
   TBranch        *b_XTOF215;   //!
   TBranch        *b_YTOF215;   //!
   TBranch        *b_ATOF215;   //!
   TBranch        *b_TTOF215;   //!
   TBranch        *b_XTOF216;   //!
   TBranch        *b_YTOF216;   //!
   TBranch        *b_ATOF216;   //!
   TBranch        *b_TTOF216;   //!
   TBranch        *b_XTOF217;   //!
   TBranch        *b_YTOF217;   //!
   TBranch        *b_ATOF217;   //!
   TBranch        *b_TTOF217;   //!
   TBranch        *b_XTOF218;   //!
   TBranch        *b_YTOF218;   //!
   TBranch        *b_ATOF218;   //!
   TBranch        *b_TTOF218;   //!
   TBranch        *b_XTOF301;   //!
   TBranch        *b_YTOF301;   //!
   TBranch        *b_ATOF301;   //!
   TBranch        *b_TTOF301;   //!
   TBranch        *b_XTOF302;   //!
   TBranch        *b_YTOF302;   //!
   TBranch        *b_ATOF302;   //!
   TBranch        *b_TTOF302;   //!
   TBranch        *b_XTOF303;   //!
   TBranch        *b_YTOF303;   //!
   TBranch        *b_ATOF303;   //!
   TBranch        *b_TTOF303;   //!
   TBranch        *b_XTOF304;   //!
   TBranch        *b_YTOF304;   //!
   TBranch        *b_ATOF304;   //!
   TBranch        *b_TTOF304;   //!
   TBranch        *b_XTOF305;   //!
   TBranch        *b_YTOF305;   //!
   TBranch        *b_ATOF305;   //!
   TBranch        *b_TTOF305;   //!
   TBranch        *b_XTOF306;   //!
   TBranch        *b_YTOF306;   //!
   TBranch        *b_ATOF306;   //!
   TBranch        *b_TTOF306;   //!
   TBranch        *b_XTOF307;   //!
   TBranch        *b_YTOF307;   //!
   TBranch        *b_ATOF307;   //!
   TBranch        *b_TTOF307;   //!
   TBranch        *b_XTOF308;   //!
   TBranch        *b_YTOF308;   //!
   TBranch        *b_ATOF308;   //!
   TBranch        *b_TTOF308;   //!
   TBranch        *b_XTOF309;   //!
   TBranch        *b_YTOF309;   //!
   TBranch        *b_ATOF309;   //!
   TBranch        *b_TTOF309;   //!
   TBranch        *b_XTOF310;   //!
   TBranch        *b_YTOF310;   //!
   TBranch        *b_ATOF310;   //!
   TBranch        *b_TTOF310;   //!
   TBranch        *b_XTOF311;   //!
   TBranch        *b_YTOF311;   //!
   TBranch        *b_ATOF311;   //!
   TBranch        *b_TTOF311;   //!
   TBranch        *b_XTOF312;   //!
   TBranch        *b_YTOF312;   //!
   TBranch        *b_ATOF312;   //!
   TBranch        *b_TTOF312;   //!
   TBranch        *b_XTOF313;   //!
   TBranch        *b_YTOF313;   //!
   TBranch        *b_ATOF313;   //!
   TBranch        *b_TTOF313;   //!
   TBranch        *b_XTOF314;   //!
   TBranch        *b_YTOF314;   //!
   TBranch        *b_ATOF314;   //!
   TBranch        *b_TTOF314;   //!
   TBranch        *b_XTOF315;   //!
   TBranch        *b_YTOF315;   //!
   TBranch        *b_ATOF315;   //!
   TBranch        *b_TTOF315;   //!
   TBranch        *b_XTOF316;   //!
   TBranch        *b_YTOF316;   //!
   TBranch        *b_ATOF316;   //!
   TBranch        *b_TTOF316;   //!
   TBranch        *b_XTOF317;   //!
   TBranch        *b_YTOF317;   //!
   TBranch        *b_ATOF317;   //!
   TBranch        *b_TTOF317;   //!
   TBranch        *b_XTOF318;   //!
   TBranch        *b_YTOF318;   //!
   TBranch        *b_ATOF318;   //!
   TBranch        *b_TTOF318;   //!
   TBranch        *b_PKDC1;   //!
   TBranch        *b_XKDC1;   //!
   TBranch        *b_YKDC1;   //!
   TBranch        *b_ZKDC1;   //!
   TBranch        *b_XpKDC1;   //!
   TBranch        *b_YpKDC1;   //!
   TBranch        *b_PKDC2;   //!
   TBranch        *b_XKDC2;   //!
   TBranch        *b_YKDC2;   //!
   TBranch        *b_ZKDC2;   //!
   TBranch        *b_XpKDC2;   //!
   TBranch        *b_YpKDC2;   //!
   TBranch        *b_PKDC3;   //!
   TBranch        *b_XKDC3;   //!
   TBranch        *b_YKDC3;   //!
   TBranch        *b_ZKDC3;   //!
   TBranch        *b_XpKDC3;   //!
   TBranch        *b_YpKDC3;   //!
   TBranch        *b_PKDC4;   //!
   TBranch        *b_XKDC4;   //!
   TBranch        *b_YKDC4;   //!
   TBranch        *b_ZKDC4;   //!
   TBranch        *b_XpKDC4;   //!
   TBranch        *b_YpKDC4;   //!
   TBranch        *b_PKDC5;   //!
   TBranch        *b_XKDC5;   //!
   TBranch        *b_YKDC5;   //!
   TBranch        *b_ZKDC5;   //!
   TBranch        *b_XpKDC5;   //!
   TBranch        *b_YpKDC5;   //!
   TBranch        *b_PKDC6;   //!
   TBranch        *b_XKDC6;   //!
   TBranch        *b_YKDC6;   //!
   TBranch        *b_ZKDC6;   //!
   TBranch        *b_XpKDC6;   //!
   TBranch        *b_YpKDC6;   //!
   TBranch        *b_PKDC7;   //!
   TBranch        *b_XKDC7;   //!
   TBranch        *b_YKDC7;   //!
   TBranch        *b_ZKDC7;   //!
   TBranch        *b_XpKDC7;   //!
   TBranch        *b_YpKDC7;   //!
   TBranch        *b_PKDC8;   //!
   TBranch        *b_XKDC8;   //!
   TBranch        *b_YKDC8;   //!
   TBranch        *b_ZKDC8;   //!
   TBranch        *b_XpKDC8;   //!
   TBranch        *b_YpKDC8;   //!
   TBranch        *b_PKDC9;   //!
   TBranch        *b_XKDC9;   //!
   TBranch        *b_YKDC9;   //!
   TBranch        *b_ZKDC9;   //!
   TBranch        *b_XpKDC9;   //!
   TBranch        *b_YpKDC9;   //!
   TBranch        *b_PKDC10;   //!
   TBranch        *b_XKDC10;   //!
   TBranch        *b_YKDC10;   //!
   TBranch        *b_ZKDC10;   //!
   TBranch        *b_XpKDC10;   //!
   TBranch        *b_YpKDC10;   //!
   TBranch        *b_PKDC11;   //!
   TBranch        *b_XKDC11;   //!
   TBranch        *b_YKDC11;   //!
   TBranch        *b_ZKDC11;   //!
   TBranch        *b_XpKDC11;   //!
   TBranch        *b_YpKDC11;   //!
   TBranch        *b_PKDC12;   //!
   TBranch        *b_XKDC12;   //!
   TBranch        *b_YKDC12;   //!
   TBranch        *b_ZKDC12;   //!
   TBranch        *b_XpKDC12;   //!
   TBranch        *b_YpKDC12;   //!
   TBranch        *b_Trig;   //!
   TBranch        *b_VDTrig;   //!
   TBranch        *b_KDCTrig;   //!
   TBranch        *b_TOF1Trig;   //!
   TBranch        *b_TOF2Trig;   //!
   TBranch        *b_TOFTrig;   //!
   TBranch        *b_AC1Trig;   //!
   TBranch        *b_AC2Trig;   //!
   TBranch        *b_AC3Trig;   //!
   TBranch        *b_WC1Trig;   //!
   TBranch        *b_WC2Trig;   //!

   HKSTree(TTree *tree=0);
   virtual ~HKSTree();
   virtual Int_t    Cut(Long64_t entry);
   virtual Int_t    GetEntry(Long64_t entry);
   virtual Long64_t LoadTree(Long64_t entry);
   virtual void     Init(TTree *tree);
   virtual void     Loop();
   virtual Bool_t   Notify();
   virtual void     Show(Long64_t entry = -1);
};

#endif

#ifdef HKSTree_cxx
HKSTree::HKSTree(TTree *tree) : fChain(0) 
{
// if parameter tree is not specified (or zero), connect the file
// used to generate this class and read the Tree.
   if (tree == 0) {
      TFile *f = (TFile*)gROOT->GetListOfFiles()->FindObject("hks_sample.root");
      if (!f || !f->IsOpen()) {
         f = new TFile("hks_sample.root");
      }
      f->GetObject("tree",tree);

   }
   Init(tree);
}

HKSTree::~HKSTree()
{
   if (!fChain) return;
   delete fChain->GetCurrentFile();
}

Int_t HKSTree::GetEntry(Long64_t entry)
{
// Read contents of entry.
   if (!fChain) return 0;
   return fChain->GetEntry(entry);
}
Long64_t HKSTree::LoadTree(Long64_t entry)
{
// Set the environment to read one entry
   if (!fChain) return -5;
   Long64_t centry = fChain->LoadTree(entry);
   if (centry < 0) return centry;
   if (fChain->GetTreeNumber() != fCurrent) {
      fCurrent = fChain->GetTreeNumber();
      Notify();
   }
   return centry;
}

void HKSTree::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fCurrent = -1;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("evID", &evID, &b_evID);
   fChain->SetBranchAddress("KMom", &KMom, &b_KMom);
   fChain->SetBranchAddress("KTheta", &KTheta, &b_KTheta);
   fChain->SetBranchAddress("KPhi", &KPhi, &b_KPhi);
   fChain->SetBranchAddress("KXpt", &KXpt, &b_KXpt);
   fChain->SetBranchAddress("KYpt", &KYpt, &b_KYpt);
   fChain->SetBranchAddress("KXt", &KXt, &b_KXt);
   fChain->SetBranchAddress("KYt", &KYt, &b_KYt);
   fChain->SetBranchAddress("KZt", &KZt, &b_KZt);
   fChain->SetBranchAddress("KXSSi", &KXSSi, &b_KXSSi);
   fChain->SetBranchAddress("KYSSi", &KYSSi, &b_KYSSi);
   fChain->SetBranchAddress("KZSSi", &KZSSi, &b_KZSSi);
   fChain->SetBranchAddress("XpSSi", &XpSSi, &b_XpSSi);
   fChain->SetBranchAddress("YpSSi", &YpSSi, &b_YpSSi);
   fChain->SetBranchAddress("KXSSe", &KXSSe, &b_KXSSe);
   fChain->SetBranchAddress("KYSSe", &KYSSe, &b_KYSSe);
   fChain->SetBranchAddress("KZSSe", &KZSSe, &b_KZSSe);
   fChain->SetBranchAddress("XpSSe", &XpSSe, &b_XpSSe);
   fChain->SetBranchAddress("YpSSe", &YpSSe, &b_YpSSe);
   fChain->SetBranchAddress("KXPCSi", &KXPCSi, &b_KXPCSi);
   fChain->SetBranchAddress("KYPCSi", &KYPCSi, &b_KYPCSi);
   fChain->SetBranchAddress("KZPCSi", &KZPCSi, &b_KZPCSi);
   fChain->SetBranchAddress("XpPCSi", &XpPCSi, &b_XpPCSi);
   fChain->SetBranchAddress("YpPCSi", &YpPCSi, &b_YpPCSi);
   fChain->SetBranchAddress("KXPCSe", &KXPCSe, &b_KXPCSe);
   fChain->SetBranchAddress("KYPCSe", &KYPCSe, &b_KYPCSe);
   fChain->SetBranchAddress("KZPCSe", &KZPCSe, &b_KZPCSe);
   fChain->SetBranchAddress("XpPCSe", &XpPCSe, &b_XpPCSe);
   fChain->SetBranchAddress("YpPCSe", &YpPCSe, &b_YpPCSe);
   fChain->SetBranchAddress("KXQ1i", &KXQ1i, &b_KXQ1i);
   fChain->SetBranchAddress("KYQ1i", &KYQ1i, &b_KYQ1i);
   fChain->SetBranchAddress("KZQ1i", &KZQ1i, &b_KZQ1i);
   fChain->SetBranchAddress("KXpQ1i", &KXpQ1i, &b_KXpQ1i);
   fChain->SetBranchAddress("KYpQ1i", &KYpQ1i, &b_KYpQ1i);
   fChain->SetBranchAddress("KpidQ1i", &KpidQ1i, &b_KpidQ1i);
   fChain->SetBranchAddress("KXQ1e", &KXQ1e, &b_KXQ1e);
   fChain->SetBranchAddress("KYQ1e", &KYQ1e, &b_KYQ1e);
   fChain->SetBranchAddress("KZQ1e", &KZQ1e, &b_KZQ1e);
   fChain->SetBranchAddress("KpidQ1e", &KpidQ1e, &b_KpidQ1e);
   fChain->SetBranchAddress("KXQ2i", &KXQ2i, &b_KXQ2i);
   fChain->SetBranchAddress("KYQ2i", &KYQ2i, &b_KYQ2i);
   fChain->SetBranchAddress("KZQ2i", &KZQ2i, &b_KZQ2i);
   fChain->SetBranchAddress("KpidQ2i", &KpidQ2i, &b_KpidQ2i);
   fChain->SetBranchAddress("KXQ2e", &KXQ2e, &b_KXQ2e);
   fChain->SetBranchAddress("KYQ2e", &KYQ2e, &b_KYQ2e);
   fChain->SetBranchAddress("KZQ2e", &KZQ2e, &b_KZQ2e);
   fChain->SetBranchAddress("KpidQ2e", &KpidQ2e, &b_KpidQ2e);
   fChain->SetBranchAddress("KPDi", &KPDi, &b_KPDi);
   fChain->SetBranchAddress("KXDi", &KXDi, &b_KXDi);
   fChain->SetBranchAddress("KYDi", &KYDi, &b_KYDi);
   fChain->SetBranchAddress("KZDi", &KZDi, &b_KZDi);
   fChain->SetBranchAddress("KpidDi", &KpidDi, &b_KpidDi);
   fChain->SetBranchAddress("KPDe", &KPDe, &b_KPDe);
   fChain->SetBranchAddress("KXDe", &KXDe, &b_KXDe);
   fChain->SetBranchAddress("KYDe", &KYDe, &b_KYDe);
   fChain->SetBranchAddress("KZDe", &KZDe, &b_KZDe);
   fChain->SetBranchAddress("KXpDe", &KXpDe, &b_KXpDe);
   fChain->SetBranchAddress("KYpDe", &KYpDe, &b_KYpDe);
   fChain->SetBranchAddress("KpidDe", &KpidDe, &b_KpidDe);
   fChain->SetBranchAddress("KLFP1", &KLFP1, &b_KLFP1);
   fChain->SetBranchAddress("KPFP1", &KPFP1, &b_KPFP1);
   fChain->SetBranchAddress("KXFP1", &KXFP1, &b_KXFP1);
   fChain->SetBranchAddress("KYFP1", &KYFP1, &b_KYFP1);
   fChain->SetBranchAddress("KZFP1", &KZFP1, &b_KZFP1);
   fChain->SetBranchAddress("KXpFP1", &KXpFP1, &b_KXpFP1);
   fChain->SetBranchAddress("KYpFP1", &KYpFP1, &b_KYpFP1);
   fChain->SetBranchAddress("KXvFP1", &KXvFP1, &b_KXvFP1);
   fChain->SetBranchAddress("KYvFP1", &KYvFP1, &b_KYvFP1);
   fChain->SetBranchAddress("KZvFP1", &KZvFP1, &b_KZvFP1);
   fChain->SetBranchAddress("KpidFP1", &KpidFP1, &b_KpidFP1);
   fChain->SetBranchAddress("KLFP2", &KLFP2, &b_KLFP2);
   fChain->SetBranchAddress("KPFP2", &KPFP2, &b_KPFP2);
   fChain->SetBranchAddress("KXFP2", &KXFP2, &b_KXFP2);
   fChain->SetBranchAddress("KYFP2", &KYFP2, &b_KYFP2);
   fChain->SetBranchAddress("KZFP2", &KZFP2, &b_KZFP2);
   fChain->SetBranchAddress("KXpFP2", &KXpFP2, &b_KXpFP2);
   fChain->SetBranchAddress("KYpFP2", &KYpFP2, &b_KYpFP2);
   fChain->SetBranchAddress("KXvFP2", &KXvFP2, &b_KXvFP2);
   fChain->SetBranchAddress("KYvFP2", &KYvFP2, &b_KYvFP2);
   fChain->SetBranchAddress("KZvFP2", &KZvFP2, &b_KZvFP2);
   fChain->SetBranchAddress("KpidFP2", &KpidFP2, &b_KpidFP2);
   fChain->SetBranchAddress("KLFP3", &KLFP3, &b_KLFP3);
   fChain->SetBranchAddress("KPFP3", &KPFP3, &b_KPFP3);
   fChain->SetBranchAddress("KXFP3", &KXFP3, &b_KXFP3);
   fChain->SetBranchAddress("KYFP3", &KYFP3, &b_KYFP3);
   fChain->SetBranchAddress("KZFP3", &KZFP3, &b_KZFP3);
   fChain->SetBranchAddress("KXpFP3", &KXpFP3, &b_KXpFP3);
   fChain->SetBranchAddress("KYpFP3", &KYpFP3, &b_KYpFP3);
   fChain->SetBranchAddress("KXvFP3", &KXvFP3, &b_KXvFP3);
   fChain->SetBranchAddress("KYvFP3", &KYvFP3, &b_KYvFP3);
   fChain->SetBranchAddress("KZvFP3", &KZvFP3, &b_KZvFP3);
   fChain->SetBranchAddress("KpidFP3", &KpidFP3, &b_KpidFP3);
   fChain->SetBranchAddress("KLFP4", &KLFP4, &b_KLFP4);
   fChain->SetBranchAddress("KPFP4", &KPFP4, &b_KPFP4);
   fChain->SetBranchAddress("KXFP4", &KXFP4, &b_KXFP4);
   fChain->SetBranchAddress("KYFP4", &KYFP4, &b_KYFP4);
   fChain->SetBranchAddress("KZFP4", &KZFP4, &b_KZFP4);
   fChain->SetBranchAddress("KXpFP4", &KXpFP4, &b_KXpFP4);
   fChain->SetBranchAddress("KYpFP4", &KYpFP4, &b_KYpFP4);
   fChain->SetBranchAddress("KXvFP4", &KXvFP4, &b_KXvFP4);
   fChain->SetBranchAddress("KYvFP4", &KYvFP4, &b_KYvFP4);
   fChain->SetBranchAddress("KZvFP4", &KZvFP4, &b_KZvFP4);
   fChain->SetBranchAddress("KpidFP4", &KpidFP4, &b_KpidFP4);
   fChain->SetBranchAddress("KLFP5", &KLFP5, &b_KLFP5);
   fChain->SetBranchAddress("KPFP5", &KPFP5, &b_KPFP5);
   fChain->SetBranchAddress("KXFP5", &KXFP5, &b_KXFP5);
   fChain->SetBranchAddress("KYFP5", &KYFP5, &b_KYFP5);
   fChain->SetBranchAddress("KZFP5", &KZFP5, &b_KZFP5);
   fChain->SetBranchAddress("KXpFP5", &KXpFP5, &b_KXpFP5);
   fChain->SetBranchAddress("KYpFP5", &KYpFP5, &b_KYpFP5);
   fChain->SetBranchAddress("KXvFP5", &KXvFP5, &b_KXvFP5);
   fChain->SetBranchAddress("KYvFP5", &KYvFP5, &b_KYvFP5);
   fChain->SetBranchAddress("KZvFP5", &KZvFP5, &b_KZvFP5);
   fChain->SetBranchAddress("KpidFP5", &KpidFP5, &b_KpidFP5);
   fChain->SetBranchAddress("KLFP6", &KLFP6, &b_KLFP6);
   fChain->SetBranchAddress("KPFP6", &KPFP6, &b_KPFP6);
   fChain->SetBranchAddress("KXFP6", &KXFP6, &b_KXFP6);
   fChain->SetBranchAddress("KYFP6", &KYFP6, &b_KYFP6);
   fChain->SetBranchAddress("KZFP6", &KZFP6, &b_KZFP6);
   fChain->SetBranchAddress("KXpFP6", &KXpFP6, &b_KXpFP6);
   fChain->SetBranchAddress("KYpFP6", &KYpFP6, &b_KYpFP6);
   fChain->SetBranchAddress("KXvFP6", &KXvFP6, &b_KXvFP6);
   fChain->SetBranchAddress("KYvFP6", &KYvFP6, &b_KYvFP6);
   fChain->SetBranchAddress("KZvFP6", &KZvFP6, &b_KZvFP6);
   fChain->SetBranchAddress("KpidFP6", &KpidFP6, &b_KpidFP6);
   fChain->SetBranchAddress("WC1pid", &WC1pid, &b_WC1pid);
   fChain->SetBranchAddress("WC2pid", &WC2pid, &b_WC2pid);
   fChain->SetBranchAddress("XWC101", &XWC101, &b_XWC101);
   fChain->SetBranchAddress("YWC101", &YWC101, &b_YWC101);
   fChain->SetBranchAddress("ZWC101", &ZWC101, &b_ZWC101);
   fChain->SetBranchAddress("AWC101", &AWC101, &b_AWC101);
   fChain->SetBranchAddress("TWC101", &TWC101, &b_TWC101);
   fChain->SetBranchAddress("XWC102", &XWC102, &b_XWC102);
   fChain->SetBranchAddress("YWC102", &YWC102, &b_YWC102);
   fChain->SetBranchAddress("ZWC102", &ZWC102, &b_ZWC102);
   fChain->SetBranchAddress("AWC102", &AWC102, &b_AWC102);
   fChain->SetBranchAddress("TWC102", &TWC102, &b_TWC102);
   fChain->SetBranchAddress("XWC103", &XWC103, &b_XWC103);
   fChain->SetBranchAddress("YWC103", &YWC103, &b_YWC103);
   fChain->SetBranchAddress("ZWC103", &ZWC103, &b_ZWC103);
   fChain->SetBranchAddress("AWC103", &AWC103, &b_AWC103);
   fChain->SetBranchAddress("TWC103", &TWC103, &b_TWC103);
   fChain->SetBranchAddress("XWC104", &XWC104, &b_XWC104);
   fChain->SetBranchAddress("YWC104", &YWC104, &b_YWC104);
   fChain->SetBranchAddress("ZWC104", &ZWC104, &b_ZWC104);
   fChain->SetBranchAddress("AWC104", &AWC104, &b_AWC104);
   fChain->SetBranchAddress("TWC104", &TWC104, &b_TWC104);
   fChain->SetBranchAddress("XWC105", &XWC105, &b_XWC105);
   fChain->SetBranchAddress("YWC105", &YWC105, &b_YWC105);
   fChain->SetBranchAddress("ZWC105", &ZWC105, &b_ZWC105);
   fChain->SetBranchAddress("AWC105", &AWC105, &b_AWC105);
   fChain->SetBranchAddress("TWC105", &TWC105, &b_TWC105);
   fChain->SetBranchAddress("XWC106", &XWC106, &b_XWC106);
   fChain->SetBranchAddress("YWC106", &YWC106, &b_YWC106);
   fChain->SetBranchAddress("ZWC106", &ZWC106, &b_ZWC106);
   fChain->SetBranchAddress("AWC106", &AWC106, &b_AWC106);
   fChain->SetBranchAddress("TWC106", &TWC106, &b_TWC106);
   fChain->SetBranchAddress("XWC107", &XWC107, &b_XWC107);
   fChain->SetBranchAddress("YWC107", &YWC107, &b_YWC107);
   fChain->SetBranchAddress("ZWC107", &ZWC107, &b_ZWC107);
   fChain->SetBranchAddress("AWC107", &AWC107, &b_AWC107);
   fChain->SetBranchAddress("TWC107", &TWC107, &b_TWC107);
   fChain->SetBranchAddress("XWC108", &XWC108, &b_XWC108);
   fChain->SetBranchAddress("YWC108", &YWC108, &b_YWC108);
   fChain->SetBranchAddress("ZWC108", &ZWC108, &b_ZWC108);
   fChain->SetBranchAddress("AWC108", &AWC108, &b_AWC108);
   fChain->SetBranchAddress("TWC108", &TWC108, &b_TWC108);
   fChain->SetBranchAddress("XWC109", &XWC109, &b_XWC109);
   fChain->SetBranchAddress("YWC109", &YWC109, &b_YWC109);
   fChain->SetBranchAddress("ZWC109", &ZWC109, &b_ZWC109);
   fChain->SetBranchAddress("AWC109", &AWC109, &b_AWC109);
   fChain->SetBranchAddress("TWC109", &TWC109, &b_TWC109);
   fChain->SetBranchAddress("XWC110", &XWC110, &b_XWC110);
   fChain->SetBranchAddress("YWC110", &YWC110, &b_YWC110);
   fChain->SetBranchAddress("ZWC110", &ZWC110, &b_ZWC110);
   fChain->SetBranchAddress("AWC110", &AWC110, &b_AWC110);
   fChain->SetBranchAddress("TWC110", &TWC110, &b_TWC110);
   fChain->SetBranchAddress("XWC111", &XWC111, &b_XWC111);
   fChain->SetBranchAddress("YWC111", &YWC111, &b_YWC111);
   fChain->SetBranchAddress("ZWC111", &ZWC111, &b_ZWC111);
   fChain->SetBranchAddress("AWC111", &AWC111, &b_AWC111);
   fChain->SetBranchAddress("TWC111", &TWC111, &b_TWC111);
   fChain->SetBranchAddress("XWC112", &XWC112, &b_XWC112);
   fChain->SetBranchAddress("YWC112", &YWC112, &b_YWC112);
   fChain->SetBranchAddress("ZWC112", &ZWC112, &b_ZWC112);
   fChain->SetBranchAddress("AWC112", &AWC112, &b_AWC112);
   fChain->SetBranchAddress("TWC112", &TWC112, &b_TWC112);
   fChain->SetBranchAddress("XWC201", &XWC201, &b_XWC201);
   fChain->SetBranchAddress("YWC201", &YWC201, &b_YWC201);
   fChain->SetBranchAddress("ZWC201", &ZWC201, &b_ZWC201);
   fChain->SetBranchAddress("AWC201", &AWC201, &b_AWC201);
   fChain->SetBranchAddress("TWC201", &TWC201, &b_TWC201);
   fChain->SetBranchAddress("XWC202", &XWC202, &b_XWC202);
   fChain->SetBranchAddress("YWC202", &YWC202, &b_YWC202);
   fChain->SetBranchAddress("ZWC202", &ZWC202, &b_ZWC202);
   fChain->SetBranchAddress("AWC202", &AWC202, &b_AWC202);
   fChain->SetBranchAddress("TWC202", &TWC202, &b_TWC202);
   fChain->SetBranchAddress("XWC203", &XWC203, &b_XWC203);
   fChain->SetBranchAddress("YWC203", &YWC203, &b_YWC203);
   fChain->SetBranchAddress("ZWC203", &ZWC203, &b_ZWC203);
   fChain->SetBranchAddress("AWC203", &AWC203, &b_AWC203);
   fChain->SetBranchAddress("TWC203", &TWC203, &b_TWC203);
   fChain->SetBranchAddress("XWC204", &XWC204, &b_XWC204);
   fChain->SetBranchAddress("YWC204", &YWC204, &b_YWC204);
   fChain->SetBranchAddress("ZWC204", &ZWC204, &b_ZWC204);
   fChain->SetBranchAddress("AWC204", &AWC204, &b_AWC204);
   fChain->SetBranchAddress("TWC204", &TWC204, &b_TWC204);
   fChain->SetBranchAddress("XWC205", &XWC205, &b_XWC205);
   fChain->SetBranchAddress("YWC205", &YWC205, &b_YWC205);
   fChain->SetBranchAddress("ZWC205", &ZWC205, &b_ZWC205);
   fChain->SetBranchAddress("AWC205", &AWC205, &b_AWC205);
   fChain->SetBranchAddress("TWC205", &TWC205, &b_TWC205);
   fChain->SetBranchAddress("XWC206", &XWC206, &b_XWC206);
   fChain->SetBranchAddress("YWC206", &YWC206, &b_YWC206);
   fChain->SetBranchAddress("ZWC206", &ZWC206, &b_ZWC206);
   fChain->SetBranchAddress("AWC206", &AWC206, &b_AWC206);
   fChain->SetBranchAddress("TWC206", &TWC206, &b_TWC206);
   fChain->SetBranchAddress("XWC207", &XWC207, &b_XWC207);
   fChain->SetBranchAddress("YWC207", &YWC207, &b_YWC207);
   fChain->SetBranchAddress("ZWC207", &ZWC207, &b_ZWC207);
   fChain->SetBranchAddress("AWC207", &AWC207, &b_AWC207);
   fChain->SetBranchAddress("TWC207", &TWC207, &b_TWC207);
   fChain->SetBranchAddress("XWC208", &XWC208, &b_XWC208);
   fChain->SetBranchAddress("YWC208", &YWC208, &b_YWC208);
   fChain->SetBranchAddress("ZWC208", &ZWC208, &b_ZWC208);
   fChain->SetBranchAddress("AWC208", &AWC208, &b_AWC208);
   fChain->SetBranchAddress("TWC208", &TWC208, &b_TWC208);
   fChain->SetBranchAddress("XWC209", &XWC209, &b_XWC209);
   fChain->SetBranchAddress("YWC209", &YWC209, &b_YWC209);
   fChain->SetBranchAddress("ZWC209", &ZWC209, &b_ZWC209);
   fChain->SetBranchAddress("AWC209", &AWC209, &b_AWC209);
   fChain->SetBranchAddress("TWC209", &TWC209, &b_TWC209);
   fChain->SetBranchAddress("XWC210", &XWC210, &b_XWC210);
   fChain->SetBranchAddress("YWC210", &YWC210, &b_YWC210);
   fChain->SetBranchAddress("ZWC210", &ZWC210, &b_ZWC210);
   fChain->SetBranchAddress("AWC210", &AWC210, &b_AWC210);
   fChain->SetBranchAddress("TWC210", &TWC210, &b_TWC210);
   fChain->SetBranchAddress("XWC211", &XWC211, &b_XWC211);
   fChain->SetBranchAddress("YWC211", &YWC211, &b_YWC211);
   fChain->SetBranchAddress("ZWC211", &ZWC211, &b_ZWC211);
   fChain->SetBranchAddress("AWC211", &AWC211, &b_AWC211);
   fChain->SetBranchAddress("TWC211", &TWC211, &b_TWC211);
   fChain->SetBranchAddress("XWC212", &XWC212, &b_XWC212);
   fChain->SetBranchAddress("YWC212", &YWC212, &b_YWC212);
   fChain->SetBranchAddress("ZWC212", &ZWC212, &b_ZWC212);
   fChain->SetBranchAddress("AWC212", &AWC212, &b_AWC212);
   fChain->SetBranchAddress("TWC212", &TWC212, &b_TWC212);
   fChain->SetBranchAddress("AC1pid", &AC1pid, &b_AC1pid);
   fChain->SetBranchAddress("AC2pid", &AC2pid, &b_AC2pid);
   fChain->SetBranchAddress("AC3pid", &AC3pid, &b_AC3pid);
   fChain->SetBranchAddress("XAC101", &XAC101, &b_XAC101);
   fChain->SetBranchAddress("YAC101", &YAC101, &b_YAC101);
   fChain->SetBranchAddress("AAC101", &AAC101, &b_AAC101);
   fChain->SetBranchAddress("TAC101", &TAC101, &b_TAC101);
   fChain->SetBranchAddress("XAC102", &XAC102, &b_XAC102);
   fChain->SetBranchAddress("YAC102", &YAC102, &b_YAC102);
   fChain->SetBranchAddress("AAC102", &AAC102, &b_AAC102);
   fChain->SetBranchAddress("TAC102", &TAC102, &b_TAC102);
   fChain->SetBranchAddress("XAC103", &XAC103, &b_XAC103);
   fChain->SetBranchAddress("YAC103", &YAC103, &b_YAC103);
   fChain->SetBranchAddress("AAC103", &AAC103, &b_AAC103);
   fChain->SetBranchAddress("TAC103", &TAC103, &b_TAC103);
   fChain->SetBranchAddress("XAC104", &XAC104, &b_XAC104);
   fChain->SetBranchAddress("YAC104", &YAC104, &b_YAC104);
   fChain->SetBranchAddress("AAC104", &AAC104, &b_AAC104);
   fChain->SetBranchAddress("TAC104", &TAC104, &b_TAC104);
   fChain->SetBranchAddress("XAC105", &XAC105, &b_XAC105);
   fChain->SetBranchAddress("YAC105", &YAC105, &b_YAC105);
   fChain->SetBranchAddress("AAC105", &AAC105, &b_AAC105);
   fChain->SetBranchAddress("TAC105", &TAC105, &b_TAC105);
   fChain->SetBranchAddress("XAC106", &XAC106, &b_XAC106);
   fChain->SetBranchAddress("YAC106", &YAC106, &b_YAC106);
   fChain->SetBranchAddress("AAC106", &AAC106, &b_AAC106);
   fChain->SetBranchAddress("TAC106", &TAC106, &b_TAC106);
   fChain->SetBranchAddress("XAC107", &XAC107, &b_XAC107);
   fChain->SetBranchAddress("YAC107", &YAC107, &b_YAC107);
   fChain->SetBranchAddress("AAC107", &AAC107, &b_AAC107);
   fChain->SetBranchAddress("TAC107", &TAC107, &b_TAC107);
   fChain->SetBranchAddress("XAC201", &XAC201, &b_XAC201);
   fChain->SetBranchAddress("YAC201", &YAC201, &b_YAC201);
   fChain->SetBranchAddress("AAC201", &AAC201, &b_AAC201);
   fChain->SetBranchAddress("TAC201", &TAC201, &b_TAC201);
   fChain->SetBranchAddress("XAC202", &XAC202, &b_XAC202);
   fChain->SetBranchAddress("YAC202", &YAC202, &b_YAC202);
   fChain->SetBranchAddress("AAC202", &AAC202, &b_AAC202);
   fChain->SetBranchAddress("TAC202", &TAC202, &b_TAC202);
   fChain->SetBranchAddress("XAC203", &XAC203, &b_XAC203);
   fChain->SetBranchAddress("YAC203", &YAC203, &b_YAC203);
   fChain->SetBranchAddress("AAC203", &AAC203, &b_AAC203);
   fChain->SetBranchAddress("TAC203", &TAC203, &b_TAC203);
   fChain->SetBranchAddress("XAC204", &XAC204, &b_XAC204);
   fChain->SetBranchAddress("YAC204", &YAC204, &b_YAC204);
   fChain->SetBranchAddress("AAC204", &AAC204, &b_AAC204);
   fChain->SetBranchAddress("TAC204", &TAC204, &b_TAC204);
   fChain->SetBranchAddress("XAC205", &XAC205, &b_XAC205);
   fChain->SetBranchAddress("YAC205", &YAC205, &b_YAC205);
   fChain->SetBranchAddress("AAC205", &AAC205, &b_AAC205);
   fChain->SetBranchAddress("TAC205", &TAC205, &b_TAC205);
   fChain->SetBranchAddress("XAC206", &XAC206, &b_XAC206);
   fChain->SetBranchAddress("YAC206", &YAC206, &b_YAC206);
   fChain->SetBranchAddress("AAC206", &AAC206, &b_AAC206);
   fChain->SetBranchAddress("TAC206", &TAC206, &b_TAC206);
   fChain->SetBranchAddress("XAC207", &XAC207, &b_XAC207);
   fChain->SetBranchAddress("YAC207", &YAC207, &b_YAC207);
   fChain->SetBranchAddress("AAC207", &AAC207, &b_AAC207);
   fChain->SetBranchAddress("TAC207", &TAC207, &b_TAC207);
   fChain->SetBranchAddress("XAC301", &XAC301, &b_XAC301);
   fChain->SetBranchAddress("YAC301", &YAC301, &b_YAC301);
   fChain->SetBranchAddress("AAC301", &AAC301, &b_AAC301);
   fChain->SetBranchAddress("TAC301", &TAC301, &b_TAC301);
   fChain->SetBranchAddress("XAC302", &XAC302, &b_XAC302);
   fChain->SetBranchAddress("YAC302", &YAC302, &b_YAC302);
   fChain->SetBranchAddress("AAC302", &AAC302, &b_AAC302);
   fChain->SetBranchAddress("TAC302", &TAC302, &b_TAC302);
   fChain->SetBranchAddress("XAC303", &XAC303, &b_XAC303);
   fChain->SetBranchAddress("YAC303", &YAC303, &b_YAC303);
   fChain->SetBranchAddress("AAC303", &AAC303, &b_AAC303);
   fChain->SetBranchAddress("TAC303", &TAC303, &b_TAC303);
   fChain->SetBranchAddress("XAC304", &XAC304, &b_XAC304);
   fChain->SetBranchAddress("YAC304", &YAC304, &b_YAC304);
   fChain->SetBranchAddress("AAC304", &AAC304, &b_AAC304);
   fChain->SetBranchAddress("TAC304", &TAC304, &b_TAC304);
   fChain->SetBranchAddress("XAC305", &XAC305, &b_XAC305);
   fChain->SetBranchAddress("YAC305", &YAC305, &b_YAC305);
   fChain->SetBranchAddress("AAC305", &AAC305, &b_AAC305);
   fChain->SetBranchAddress("TAC305", &TAC305, &b_TAC305);
   fChain->SetBranchAddress("XAC306", &XAC306, &b_XAC306);
   fChain->SetBranchAddress("YAC306", &YAC306, &b_YAC306);
   fChain->SetBranchAddress("AAC306", &AAC306, &b_AAC306);
   fChain->SetBranchAddress("TAC306", &TAC306, &b_TAC306);
   fChain->SetBranchAddress("XAC307", &XAC307, &b_XAC307);
   fChain->SetBranchAddress("YAC307", &YAC307, &b_YAC307);
   fChain->SetBranchAddress("AAC307", &AAC307, &b_AAC307);
   fChain->SetBranchAddress("TAC307", &TAC307, &b_TAC307);
   fChain->SetBranchAddress("TOF1Xpid", &TOF1Xpid, &b_TOF1Xpid);
   fChain->SetBranchAddress("TOF1Ypid", &TOF1Ypid, &b_TOF1Ypid);
   fChain->SetBranchAddress("TOF2Xpid", &TOF2Xpid, &b_TOF2Xpid);
   fChain->SetBranchAddress("TTOF1X", &TTOF1X, &b_TTOF1X);
   fChain->SetBranchAddress("TTOF1Y", &TTOF1Y, &b_TTOF1Y);
   fChain->SetBranchAddress("TTOF2X", &TTOF2X, &b_TTOF2X);
   fChain->SetBranchAddress("LTOF1X", &LTOF1X, &b_LTOF1X);
   fChain->SetBranchAddress("LTOF1Y", &LTOF1Y, &b_LTOF1Y);
   fChain->SetBranchAddress("LTOF2X", &LTOF2X, &b_LTOF2X);
   fChain->SetBranchAddress("XTOF101", &XTOF101, &b_XTOF101);
   fChain->SetBranchAddress("YTOF101", &YTOF101, &b_YTOF101);
   fChain->SetBranchAddress("ATOF101", &ATOF101, &b_ATOF101);
   fChain->SetBranchAddress("TTOF101", &TTOF101, &b_TTOF101);
   fChain->SetBranchAddress("XTOF102", &XTOF102, &b_XTOF102);
   fChain->SetBranchAddress("YTOF102", &YTOF102, &b_YTOF102);
   fChain->SetBranchAddress("ATOF102", &ATOF102, &b_ATOF102);
   fChain->SetBranchAddress("TTOF102", &TTOF102, &b_TTOF102);
   fChain->SetBranchAddress("XTOF103", &XTOF103, &b_XTOF103);
   fChain->SetBranchAddress("YTOF103", &YTOF103, &b_YTOF103);
   fChain->SetBranchAddress("ATOF103", &ATOF103, &b_ATOF103);
   fChain->SetBranchAddress("TTOF103", &TTOF103, &b_TTOF103);
   fChain->SetBranchAddress("XTOF104", &XTOF104, &b_XTOF104);
   fChain->SetBranchAddress("YTOF104", &YTOF104, &b_YTOF104);
   fChain->SetBranchAddress("ATOF104", &ATOF104, &b_ATOF104);
   fChain->SetBranchAddress("TTOF104", &TTOF104, &b_TTOF104);
   fChain->SetBranchAddress("XTOF105", &XTOF105, &b_XTOF105);
   fChain->SetBranchAddress("YTOF105", &YTOF105, &b_YTOF105);
   fChain->SetBranchAddress("ATOF105", &ATOF105, &b_ATOF105);
   fChain->SetBranchAddress("TTOF105", &TTOF105, &b_TTOF105);
   fChain->SetBranchAddress("XTOF106", &XTOF106, &b_XTOF106);
   fChain->SetBranchAddress("YTOF106", &YTOF106, &b_YTOF106);
   fChain->SetBranchAddress("ATOF106", &ATOF106, &b_ATOF106);
   fChain->SetBranchAddress("TTOF106", &TTOF106, &b_TTOF106);
   fChain->SetBranchAddress("XTOF107", &XTOF107, &b_XTOF107);
   fChain->SetBranchAddress("YTOF107", &YTOF107, &b_YTOF107);
   fChain->SetBranchAddress("ATOF107", &ATOF107, &b_ATOF107);
   fChain->SetBranchAddress("TTOF107", &TTOF107, &b_TTOF107);
   fChain->SetBranchAddress("XTOF108", &XTOF108, &b_XTOF108);
   fChain->SetBranchAddress("YTOF108", &YTOF108, &b_YTOF108);
   fChain->SetBranchAddress("ATOF108", &ATOF108, &b_ATOF108);
   fChain->SetBranchAddress("TTOF108", &TTOF108, &b_TTOF108);
   fChain->SetBranchAddress("XTOF109", &XTOF109, &b_XTOF109);
   fChain->SetBranchAddress("YTOF109", &YTOF109, &b_YTOF109);
   fChain->SetBranchAddress("ATOF109", &ATOF109, &b_ATOF109);
   fChain->SetBranchAddress("TTOF109", &TTOF109, &b_TTOF109);
   fChain->SetBranchAddress("XTOF110", &XTOF110, &b_XTOF110);
   fChain->SetBranchAddress("YTOF110", &YTOF110, &b_YTOF110);
   fChain->SetBranchAddress("ATOF110", &ATOF110, &b_ATOF110);
   fChain->SetBranchAddress("TTOF110", &TTOF110, &b_TTOF110);
   fChain->SetBranchAddress("XTOF111", &XTOF111, &b_XTOF111);
   fChain->SetBranchAddress("YTOF111", &YTOF111, &b_YTOF111);
   fChain->SetBranchAddress("ATOF111", &ATOF111, &b_ATOF111);
   fChain->SetBranchAddress("TTOF111", &TTOF111, &b_TTOF111);
   fChain->SetBranchAddress("XTOF112", &XTOF112, &b_XTOF112);
   fChain->SetBranchAddress("YTOF112", &YTOF112, &b_YTOF112);
   fChain->SetBranchAddress("ATOF112", &ATOF112, &b_ATOF112);
   fChain->SetBranchAddress("TTOF112", &TTOF112, &b_TTOF112);
   fChain->SetBranchAddress("XTOF113", &XTOF113, &b_XTOF113);
   fChain->SetBranchAddress("YTOF113", &YTOF113, &b_YTOF113);
   fChain->SetBranchAddress("ATOF113", &ATOF113, &b_ATOF113);
   fChain->SetBranchAddress("TTOF113", &TTOF113, &b_TTOF113);
   fChain->SetBranchAddress("XTOF114", &XTOF114, &b_XTOF114);
   fChain->SetBranchAddress("YTOF114", &YTOF114, &b_YTOF114);
   fChain->SetBranchAddress("ATOF114", &ATOF114, &b_ATOF114);
   fChain->SetBranchAddress("TTOF114", &TTOF114, &b_TTOF114);
   fChain->SetBranchAddress("XTOF115", &XTOF115, &b_XTOF115);
   fChain->SetBranchAddress("YTOF115", &YTOF115, &b_YTOF115);
   fChain->SetBranchAddress("ATOF115", &ATOF115, &b_ATOF115);
   fChain->SetBranchAddress("TTOF115", &TTOF115, &b_TTOF115);
   fChain->SetBranchAddress("XTOF116", &XTOF116, &b_XTOF116);
   fChain->SetBranchAddress("YTOF116", &YTOF116, &b_YTOF116);
   fChain->SetBranchAddress("ATOF116", &ATOF116, &b_ATOF116);
   fChain->SetBranchAddress("TTOF116", &TTOF116, &b_TTOF116);
   fChain->SetBranchAddress("XTOF117", &XTOF117, &b_XTOF117);
   fChain->SetBranchAddress("YTOF117", &YTOF117, &b_YTOF117);
   fChain->SetBranchAddress("ATOF117", &ATOF117, &b_ATOF117);
   fChain->SetBranchAddress("TTOF117", &TTOF117, &b_TTOF117);
   fChain->SetBranchAddress("XTOF118", &XTOF118, &b_XTOF118);
   fChain->SetBranchAddress("YTOF118", &YTOF118, &b_YTOF118);
   fChain->SetBranchAddress("ATOF118", &ATOF118, &b_ATOF118);
   fChain->SetBranchAddress("TTOF118", &TTOF118, &b_TTOF118);
   fChain->SetBranchAddress("XTOF201", &XTOF201, &b_XTOF201);
   fChain->SetBranchAddress("YTOF201", &YTOF201, &b_YTOF201);
   fChain->SetBranchAddress("ATOF201", &ATOF201, &b_ATOF201);
   fChain->SetBranchAddress("TTOF201", &TTOF201, &b_TTOF201);
   fChain->SetBranchAddress("XTOF202", &XTOF202, &b_XTOF202);
   fChain->SetBranchAddress("YTOF202", &YTOF202, &b_YTOF202);
   fChain->SetBranchAddress("ATOF202", &ATOF202, &b_ATOF202);
   fChain->SetBranchAddress("TTOF202", &TTOF202, &b_TTOF202);
   fChain->SetBranchAddress("XTOF203", &XTOF203, &b_XTOF203);
   fChain->SetBranchAddress("YTOF203", &YTOF203, &b_YTOF203);
   fChain->SetBranchAddress("ATOF203", &ATOF203, &b_ATOF203);
   fChain->SetBranchAddress("TTOF203", &TTOF203, &b_TTOF203);
   fChain->SetBranchAddress("XTOF204", &XTOF204, &b_XTOF204);
   fChain->SetBranchAddress("YTOF204", &YTOF204, &b_YTOF204);
   fChain->SetBranchAddress("ATOF204", &ATOF204, &b_ATOF204);
   fChain->SetBranchAddress("TTOF204", &TTOF204, &b_TTOF204);
   fChain->SetBranchAddress("XTOF205", &XTOF205, &b_XTOF205);
   fChain->SetBranchAddress("YTOF205", &YTOF205, &b_YTOF205);
   fChain->SetBranchAddress("ATOF205", &ATOF205, &b_ATOF205);
   fChain->SetBranchAddress("TTOF205", &TTOF205, &b_TTOF205);
   fChain->SetBranchAddress("XTOF206", &XTOF206, &b_XTOF206);
   fChain->SetBranchAddress("YTOF206", &YTOF206, &b_YTOF206);
   fChain->SetBranchAddress("ATOF206", &ATOF206, &b_ATOF206);
   fChain->SetBranchAddress("TTOF206", &TTOF206, &b_TTOF206);
   fChain->SetBranchAddress("XTOF207", &XTOF207, &b_XTOF207);
   fChain->SetBranchAddress("YTOF207", &YTOF207, &b_YTOF207);
   fChain->SetBranchAddress("ATOF207", &ATOF207, &b_ATOF207);
   fChain->SetBranchAddress("TTOF207", &TTOF207, &b_TTOF207);
   fChain->SetBranchAddress("XTOF208", &XTOF208, &b_XTOF208);
   fChain->SetBranchAddress("YTOF208", &YTOF208, &b_YTOF208);
   fChain->SetBranchAddress("ATOF208", &ATOF208, &b_ATOF208);
   fChain->SetBranchAddress("TTOF208", &TTOF208, &b_TTOF208);
   fChain->SetBranchAddress("XTOF209", &XTOF209, &b_XTOF209);
   fChain->SetBranchAddress("YTOF209", &YTOF209, &b_YTOF209);
   fChain->SetBranchAddress("ATOF209", &ATOF209, &b_ATOF209);
   fChain->SetBranchAddress("TTOF209", &TTOF209, &b_TTOF209);
   fChain->SetBranchAddress("XTOF210", &XTOF210, &b_XTOF210);
   fChain->SetBranchAddress("YTOF210", &YTOF210, &b_YTOF210);
   fChain->SetBranchAddress("ATOF210", &ATOF210, &b_ATOF210);
   fChain->SetBranchAddress("TTOF210", &TTOF210, &b_TTOF210);
   fChain->SetBranchAddress("XTOF211", &XTOF211, &b_XTOF211);
   fChain->SetBranchAddress("YTOF211", &YTOF211, &b_YTOF211);
   fChain->SetBranchAddress("ATOF211", &ATOF211, &b_ATOF211);
   fChain->SetBranchAddress("TTOF211", &TTOF211, &b_TTOF211);
   fChain->SetBranchAddress("XTOF212", &XTOF212, &b_XTOF212);
   fChain->SetBranchAddress("YTOF212", &YTOF212, &b_YTOF212);
   fChain->SetBranchAddress("ATOF212", &ATOF212, &b_ATOF212);
   fChain->SetBranchAddress("TTOF212", &TTOF212, &b_TTOF212);
   fChain->SetBranchAddress("XTOF213", &XTOF213, &b_XTOF213);
   fChain->SetBranchAddress("YTOF213", &YTOF213, &b_YTOF213);
   fChain->SetBranchAddress("ATOF213", &ATOF213, &b_ATOF213);
   fChain->SetBranchAddress("TTOF213", &TTOF213, &b_TTOF213);
   fChain->SetBranchAddress("XTOF214", &XTOF214, &b_XTOF214);
   fChain->SetBranchAddress("YTOF214", &YTOF214, &b_YTOF214);
   fChain->SetBranchAddress("ATOF214", &ATOF214, &b_ATOF214);
   fChain->SetBranchAddress("TTOF214", &TTOF214, &b_TTOF214);
   fChain->SetBranchAddress("XTOF215", &XTOF215, &b_XTOF215);
   fChain->SetBranchAddress("YTOF215", &YTOF215, &b_YTOF215);
   fChain->SetBranchAddress("ATOF215", &ATOF215, &b_ATOF215);
   fChain->SetBranchAddress("TTOF215", &TTOF215, &b_TTOF215);
   fChain->SetBranchAddress("XTOF216", &XTOF216, &b_XTOF216);
   fChain->SetBranchAddress("YTOF216", &YTOF216, &b_YTOF216);
   fChain->SetBranchAddress("ATOF216", &ATOF216, &b_ATOF216);
   fChain->SetBranchAddress("TTOF216", &TTOF216, &b_TTOF216);
   fChain->SetBranchAddress("XTOF217", &XTOF217, &b_XTOF217);
   fChain->SetBranchAddress("YTOF217", &YTOF217, &b_YTOF217);
   fChain->SetBranchAddress("ATOF217", &ATOF217, &b_ATOF217);
   fChain->SetBranchAddress("TTOF217", &TTOF217, &b_TTOF217);
   fChain->SetBranchAddress("XTOF218", &XTOF218, &b_XTOF218);
   fChain->SetBranchAddress("YTOF218", &YTOF218, &b_YTOF218);
   fChain->SetBranchAddress("ATOF218", &ATOF218, &b_ATOF218);
   fChain->SetBranchAddress("TTOF218", &TTOF218, &b_TTOF218);
   fChain->SetBranchAddress("XTOF301", &XTOF301, &b_XTOF301);
   fChain->SetBranchAddress("YTOF301", &YTOF301, &b_YTOF301);
   fChain->SetBranchAddress("ATOF301", &ATOF301, &b_ATOF301);
   fChain->SetBranchAddress("TTOF301", &TTOF301, &b_TTOF301);
   fChain->SetBranchAddress("XTOF302", &XTOF302, &b_XTOF302);
   fChain->SetBranchAddress("YTOF302", &YTOF302, &b_YTOF302);
   fChain->SetBranchAddress("ATOF302", &ATOF302, &b_ATOF302);
   fChain->SetBranchAddress("TTOF302", &TTOF302, &b_TTOF302);
   fChain->SetBranchAddress("XTOF303", &XTOF303, &b_XTOF303);
   fChain->SetBranchAddress("YTOF303", &YTOF303, &b_YTOF303);
   fChain->SetBranchAddress("ATOF303", &ATOF303, &b_ATOF303);
   fChain->SetBranchAddress("TTOF303", &TTOF303, &b_TTOF303);
   fChain->SetBranchAddress("XTOF304", &XTOF304, &b_XTOF304);
   fChain->SetBranchAddress("YTOF304", &YTOF304, &b_YTOF304);
   fChain->SetBranchAddress("ATOF304", &ATOF304, &b_ATOF304);
   fChain->SetBranchAddress("TTOF304", &TTOF304, &b_TTOF304);
   fChain->SetBranchAddress("XTOF305", &XTOF305, &b_XTOF305);
   fChain->SetBranchAddress("YTOF305", &YTOF305, &b_YTOF305);
   fChain->SetBranchAddress("ATOF305", &ATOF305, &b_ATOF305);
   fChain->SetBranchAddress("TTOF305", &TTOF305, &b_TTOF305);
   fChain->SetBranchAddress("XTOF306", &XTOF306, &b_XTOF306);
   fChain->SetBranchAddress("YTOF306", &YTOF306, &b_YTOF306);
   fChain->SetBranchAddress("ATOF306", &ATOF306, &b_ATOF306);
   fChain->SetBranchAddress("TTOF306", &TTOF306, &b_TTOF306);
   fChain->SetBranchAddress("XTOF307", &XTOF307, &b_XTOF307);
   fChain->SetBranchAddress("YTOF307", &YTOF307, &b_YTOF307);
   fChain->SetBranchAddress("ATOF307", &ATOF307, &b_ATOF307);
   fChain->SetBranchAddress("TTOF307", &TTOF307, &b_TTOF307);
   fChain->SetBranchAddress("XTOF308", &XTOF308, &b_XTOF308);
   fChain->SetBranchAddress("YTOF308", &YTOF308, &b_YTOF308);
   fChain->SetBranchAddress("ATOF308", &ATOF308, &b_ATOF308);
   fChain->SetBranchAddress("TTOF308", &TTOF308, &b_TTOF308);
   fChain->SetBranchAddress("XTOF309", &XTOF309, &b_XTOF309);
   fChain->SetBranchAddress("YTOF309", &YTOF309, &b_YTOF309);
   fChain->SetBranchAddress("ATOF309", &ATOF309, &b_ATOF309);
   fChain->SetBranchAddress("TTOF309", &TTOF309, &b_TTOF309);
   fChain->SetBranchAddress("XTOF310", &XTOF310, &b_XTOF310);
   fChain->SetBranchAddress("YTOF310", &YTOF310, &b_YTOF310);
   fChain->SetBranchAddress("ATOF310", &ATOF310, &b_ATOF310);
   fChain->SetBranchAddress("TTOF310", &TTOF310, &b_TTOF310);
   fChain->SetBranchAddress("XTOF311", &XTOF311, &b_XTOF311);
   fChain->SetBranchAddress("YTOF311", &YTOF311, &b_YTOF311);
   fChain->SetBranchAddress("ATOF311", &ATOF311, &b_ATOF311);
   fChain->SetBranchAddress("TTOF311", &TTOF311, &b_TTOF311);
   fChain->SetBranchAddress("XTOF312", &XTOF312, &b_XTOF312);
   fChain->SetBranchAddress("YTOF312", &YTOF312, &b_YTOF312);
   fChain->SetBranchAddress("ATOF312", &ATOF312, &b_ATOF312);
   fChain->SetBranchAddress("TTOF312", &TTOF312, &b_TTOF312);
   fChain->SetBranchAddress("XTOF313", &XTOF313, &b_XTOF313);
   fChain->SetBranchAddress("YTOF313", &YTOF313, &b_YTOF313);
   fChain->SetBranchAddress("ATOF313", &ATOF313, &b_ATOF313);
   fChain->SetBranchAddress("TTOF313", &TTOF313, &b_TTOF313);
   fChain->SetBranchAddress("XTOF314", &XTOF314, &b_XTOF314);
   fChain->SetBranchAddress("YTOF314", &YTOF314, &b_YTOF314);
   fChain->SetBranchAddress("ATOF314", &ATOF314, &b_ATOF314);
   fChain->SetBranchAddress("TTOF314", &TTOF314, &b_TTOF314);
   fChain->SetBranchAddress("XTOF315", &XTOF315, &b_XTOF315);
   fChain->SetBranchAddress("YTOF315", &YTOF315, &b_YTOF315);
   fChain->SetBranchAddress("ATOF315", &ATOF315, &b_ATOF315);
   fChain->SetBranchAddress("TTOF315", &TTOF315, &b_TTOF315);
   fChain->SetBranchAddress("XTOF316", &XTOF316, &b_XTOF316);
   fChain->SetBranchAddress("YTOF316", &YTOF316, &b_YTOF316);
   fChain->SetBranchAddress("ATOF316", &ATOF316, &b_ATOF316);
   fChain->SetBranchAddress("TTOF316", &TTOF316, &b_TTOF316);
   fChain->SetBranchAddress("XTOF317", &XTOF317, &b_XTOF317);
   fChain->SetBranchAddress("YTOF317", &YTOF317, &b_YTOF317);
   fChain->SetBranchAddress("ATOF317", &ATOF317, &b_ATOF317);
   fChain->SetBranchAddress("TTOF317", &TTOF317, &b_TTOF317);
   fChain->SetBranchAddress("XTOF318", &XTOF318, &b_XTOF318);
   fChain->SetBranchAddress("YTOF318", &YTOF318, &b_YTOF318);
   fChain->SetBranchAddress("ATOF318", &ATOF318, &b_ATOF318);
   fChain->SetBranchAddress("TTOF318", &TTOF318, &b_TTOF318);
   fChain->SetBranchAddress("PKDC1", &PKDC1, &b_PKDC1);
   fChain->SetBranchAddress("XKDC1", &XKDC1, &b_XKDC1);
   fChain->SetBranchAddress("YKDC1", &YKDC1, &b_YKDC1);
   fChain->SetBranchAddress("ZKDC1", &ZKDC1, &b_ZKDC1);
   fChain->SetBranchAddress("XpKDC1", &XpKDC1, &b_XpKDC1);
   fChain->SetBranchAddress("YpKDC1", &YpKDC1, &b_YpKDC1);
   fChain->SetBranchAddress("PKDC2", &PKDC2, &b_PKDC2);
   fChain->SetBranchAddress("XKDC2", &XKDC2, &b_XKDC2);
   fChain->SetBranchAddress("YKDC2", &YKDC2, &b_YKDC2);
   fChain->SetBranchAddress("ZKDC2", &ZKDC2, &b_ZKDC2);
   fChain->SetBranchAddress("XpKDC2", &XpKDC2, &b_XpKDC2);
   fChain->SetBranchAddress("YpKDC2", &YpKDC2, &b_YpKDC2);
   fChain->SetBranchAddress("PKDC3", &PKDC3, &b_PKDC3);
   fChain->SetBranchAddress("XKDC3", &XKDC3, &b_XKDC3);
   fChain->SetBranchAddress("YKDC3", &YKDC3, &b_YKDC3);
   fChain->SetBranchAddress("ZKDC3", &ZKDC3, &b_ZKDC3);
   fChain->SetBranchAddress("XpKDC3", &XpKDC3, &b_XpKDC3);
   fChain->SetBranchAddress("YpKDC3", &YpKDC3, &b_YpKDC3);
   fChain->SetBranchAddress("PKDC4", &PKDC4, &b_PKDC4);
   fChain->SetBranchAddress("XKDC4", &XKDC4, &b_XKDC4);
   fChain->SetBranchAddress("YKDC4", &YKDC4, &b_YKDC4);
   fChain->SetBranchAddress("ZKDC4", &ZKDC4, &b_ZKDC4);
   fChain->SetBranchAddress("XpKDC4", &XpKDC4, &b_XpKDC4);
   fChain->SetBranchAddress("YpKDC4", &YpKDC4, &b_YpKDC4);
   fChain->SetBranchAddress("PKDC5", &PKDC5, &b_PKDC5);
   fChain->SetBranchAddress("XKDC5", &XKDC5, &b_XKDC5);
   fChain->SetBranchAddress("YKDC5", &YKDC5, &b_YKDC5);
   fChain->SetBranchAddress("ZKDC5", &ZKDC5, &b_ZKDC5);
   fChain->SetBranchAddress("XpKDC5", &XpKDC5, &b_XpKDC5);
   fChain->SetBranchAddress("YpKDC5", &YpKDC5, &b_YpKDC5);
   fChain->SetBranchAddress("PKDC6", &PKDC6, &b_PKDC6);
   fChain->SetBranchAddress("XKDC6", &XKDC6, &b_XKDC6);
   fChain->SetBranchAddress("YKDC6", &YKDC6, &b_YKDC6);
   fChain->SetBranchAddress("ZKDC6", &ZKDC6, &b_ZKDC6);
   fChain->SetBranchAddress("XpKDC6", &XpKDC6, &b_XpKDC6);
   fChain->SetBranchAddress("YpKDC6", &YpKDC6, &b_YpKDC6);
   fChain->SetBranchAddress("PKDC7", &PKDC7, &b_PKDC7);
   fChain->SetBranchAddress("XKDC7", &XKDC7, &b_XKDC7);
   fChain->SetBranchAddress("YKDC7", &YKDC7, &b_YKDC7);
   fChain->SetBranchAddress("ZKDC7", &ZKDC7, &b_ZKDC7);
   fChain->SetBranchAddress("XpKDC7", &XpKDC7, &b_XpKDC7);
   fChain->SetBranchAddress("YpKDC7", &YpKDC7, &b_YpKDC7);
   fChain->SetBranchAddress("PKDC8", &PKDC8, &b_PKDC8);
   fChain->SetBranchAddress("XKDC8", &XKDC8, &b_XKDC8);
   fChain->SetBranchAddress("YKDC8", &YKDC8, &b_YKDC8);
   fChain->SetBranchAddress("ZKDC8", &ZKDC8, &b_ZKDC8);
   fChain->SetBranchAddress("XpKDC8", &XpKDC8, &b_XpKDC8);
   fChain->SetBranchAddress("YpKDC8", &YpKDC8, &b_YpKDC8);
   fChain->SetBranchAddress("PKDC9", &PKDC9, &b_PKDC9);
   fChain->SetBranchAddress("XKDC9", &XKDC9, &b_XKDC9);
   fChain->SetBranchAddress("YKDC9", &YKDC9, &b_YKDC9);
   fChain->SetBranchAddress("ZKDC9", &ZKDC9, &b_ZKDC9);
   fChain->SetBranchAddress("XpKDC9", &XpKDC9, &b_XpKDC9);
   fChain->SetBranchAddress("YpKDC9", &YpKDC9, &b_YpKDC9);
   fChain->SetBranchAddress("PKDC10", &PKDC10, &b_PKDC10);
   fChain->SetBranchAddress("XKDC10", &XKDC10, &b_XKDC10);
   fChain->SetBranchAddress("YKDC10", &YKDC10, &b_YKDC10);
   fChain->SetBranchAddress("ZKDC10", &ZKDC10, &b_ZKDC10);
   fChain->SetBranchAddress("XpKDC10", &XpKDC10, &b_XpKDC10);
   fChain->SetBranchAddress("YpKDC10", &YpKDC10, &b_YpKDC10);
   fChain->SetBranchAddress("PKDC11", &PKDC11, &b_PKDC11);
   fChain->SetBranchAddress("XKDC11", &XKDC11, &b_XKDC11);
   fChain->SetBranchAddress("YKDC11", &YKDC11, &b_YKDC11);
   fChain->SetBranchAddress("ZKDC11", &ZKDC11, &b_ZKDC11);
   fChain->SetBranchAddress("XpKDC11", &XpKDC11, &b_XpKDC11);
   fChain->SetBranchAddress("YpKDC11", &YpKDC11, &b_YpKDC11);
   fChain->SetBranchAddress("PKDC12", &PKDC12, &b_PKDC12);
   fChain->SetBranchAddress("XKDC12", &XKDC12, &b_XKDC12);
   fChain->SetBranchAddress("YKDC12", &YKDC12, &b_YKDC12);
   fChain->SetBranchAddress("ZKDC12", &ZKDC12, &b_ZKDC12);
   fChain->SetBranchAddress("XpKDC12", &XpKDC12, &b_XpKDC12);
   fChain->SetBranchAddress("YpKDC12", &YpKDC12, &b_YpKDC12);
   fChain->SetBranchAddress("Trig", &Trig, &b_Trig);
   fChain->SetBranchAddress("VDTrig", &VDTrig, &b_VDTrig);
   fChain->SetBranchAddress("KDCTrig", &KDCTrig, &b_KDCTrig);
   fChain->SetBranchAddress("TOF1Trig", &TOF1Trig, &b_TOF1Trig);
   fChain->SetBranchAddress("TOF2Trig", &TOF2Trig, &b_TOF2Trig);
   fChain->SetBranchAddress("TOFTrig", &TOFTrig, &b_TOFTrig);
   fChain->SetBranchAddress("AC1Trig", &AC1Trig, &b_AC1Trig);
   fChain->SetBranchAddress("AC2Trig", &AC2Trig, &b_AC2Trig);
   fChain->SetBranchAddress("AC3Trig", &AC3Trig, &b_AC3Trig);
   fChain->SetBranchAddress("WC1Trig", &WC1Trig, &b_WC1Trig);
   fChain->SetBranchAddress("WC2Trig", &WC2Trig, &b_WC2Trig);
   Notify();
}

Bool_t HKSTree::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

void HKSTree::Show(Long64_t entry)
{
// Print contents of entry.
// If entry is not specified, print current entry
   if (!fChain) return;
   fChain->Show(entry);
}
Int_t HKSTree::Cut(Long64_t entry)
{
// This function may be called from Loop.
// returns  1 if entry is accepted.
// returns -1 otherwise.
   return 1;
}
#endif // #ifdef HKSTree_cxx
