//
//  TexLegeLibrary.h
//  TexLege
//
//  Created by Gregory Combs on 2/4/11.
//  Copyright 2011 Gregory S. Combs. All rights reserved.
//

#define OPENAPIS_DEFAULT_SESSION		@"82"
#define WNOM_DEFAULT_LATEST_SESSION		82

// Legislative Chamber / Legislator Type
enum kChambers {
    BOTH_CHAMBERS = 0,
    HOUSE,
    SENATE,
	JOINT,
	EXECUTIVE	// Used in open states / bill actions	
};

// Political Party
enum kParties {
    kUnknownParty = 0,
    DEMOCRAT,
    REPUBLICAN
};

// Committe Position Roles
enum kPositions {
    POS_MEMBER = 0,
    POS_VICE,
    POS_CHAIR
};

typedef enum  {
    TLReturnFull = 0,		// Return the full string
    TLReturnAbbrev,			// Return an abbreviation
    TLReturnInitial,		// Return an initial
	TLReturnOpenStates,
	TLReturnAbbrevPlural,	// Like "Dems", "Repubs", etc.
	TLReturnTitle			// Return a member title like Senator or Representative
} TLStringReturnType;

enum  {
	BillStageUnknown = 0,
	BillStageFiled,
	BillStageOutOfCommittee,
	BillStageChamberVoted,
	BillStageOutOfOpposingCommittee,
	BillStageOpposingChamberVoted,
	BillStageSentToGovernor,
	BillStageBecomesLaw,
	BillStageVetoed = -1
} TexLegeBillStages;
										/*
										 1. Filed
										 2. Out of (current chamber) Committee
										 3. Voted on by (current chamber)
										 4. Out of (opposing chamber) Committee
										 5. Voted on by (opposing chamber)
										 6. Submitted to Governor
										 7. Bill Becomes Law
										 */

NSString *stringInitial(NSString *inString, BOOL parens);
NSString *abbreviateString(NSString *inString);

NSInteger chamberFromOpenStatesString(NSString *chamberString);
NSString *stringForChamber(NSInteger chamber, TLStringReturnType type);
NSString *stringForParty(NSInteger party, TLStringReturnType type);
NSString *billTypeStringFromBillID(NSString *billID);
BOOL billTypeRequiresGovernor(NSString *billType);
BOOL billTypeRequiresOpposingChamber(NSString *billType);
NSString * watchIDForBill(NSDictionary *aBill);

