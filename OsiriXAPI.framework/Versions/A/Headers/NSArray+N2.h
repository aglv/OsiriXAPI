/*=========================================================================
 Program:   OsiriX
 Copyright (c) 2010 - 2018 Pixmeo SARL
 266 rue de Bernex
 CH-1233 Bernex
 Switzerland
 All rights reserved.
 =========================================================================*/

#import <Cocoa/Cocoa.h>


@interface NSArray (N2)

- (NSArray*)splitArrayIntoArraysOfMinSize:(NSUInteger)chunkSize maxArrays:(NSUInteger)maxArrays;
- (NSArray*)splitArrayIntoChunksOfMinSize:(NSUInteger)chunkSize maxChunks:(NSUInteger)maxChunks;
- (id) deepMutableCopy;
- (NSArray *)arrayByRemovingObject:(id)obj;
- (NSArray *)arrayByRemovingObjectsFromArray:(NSArray*)objs;
- (NSArray *)arrayByRemovingDuplicates;
- (NSArray *)reversedArray;
@end


@interface NSMutableArray (N2)

-(void)addUniqueObjectsFromArray:(NSArray*)array;

@end
