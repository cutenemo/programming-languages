//
// Blocks in Objective-C Example
// https://developer.apple.com/library/ios/documentation/Cocoa/Conceptual/ProgrammingWithObjectiveC/WorkingwithBlocks/WorkingwithBlocks.html
/*
 - Blocks Take Arguments and Return Values
 use ^{ for no arguments, ^(BOOL)(arguments) and ^(arguments) if return values can be inferred
 - Blocks have one method "copy"
 - Blocks Can Capture Values from the Enclosing Scope (lexical scope)
 - Use __block Variables to Share Storage
 - You Can Pass Blocks as Arguments to Methods or Functions
 - A Block Should Always Be the Last Argument to a Method
 - Blocks maintain strong references to any captured objects, including self
    [self.myBlock addObject:^{
    [self doSomething]; // bad self has a strong pointer to the block
                        // and the block has a strong pointer to self
                        // self should be declared as a weak pointer
    }];
 - Use Type Definitions to Simplify Block Syntax
 - Objects Use Properties to Keep Track of Blocks
 - Use Block Operations with Operation Queues
 - Schedule Blocks on Dispatch Queues with Grand Central Dispatch
*/

#import "Test.h"
#import "Foo.h"

@interface Test()
@end

@implementation Test
- (void)someMethod {
    __block double stopValue = 1.1;
    NSDictionary *d = [[NSDictionary alloc] init];

    // blocks starts with a ^ sign
    [d enumerateKeysAndObjectsUsingBlock:^(id key, id obj, BOOL *stop) {
        NSLog(@"value for key %@ is %@", key, obj);

        // can use local variable stopValue (readonly unless __block is used)
        if ([@"Enough" isEqualToString:key] || ([obj doubleValue] == stopValue)) {
            *stop = YES;
        }
    }];
}
@end