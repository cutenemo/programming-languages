//
//  Foo.h
//  Example Protocol in Objective-C
//  - A protocol is used to declare methods and properties that are
//  independent of any specific class
//  - Alternative to subclassing to provide non-generic behavoir
//

#import <Foundation/Foundation.h>

@protocol Foo <NSObject> // in order to implement Foo you also need to implement all the methods in the NSObject Protocol
- (void)someMethod;
@optional
- (void)someOptionalMethod:(BOOL)argument;
@required
@property (readonly) int readonlyProperty;
@property NSString *readwriteProperty;
-(int)someMethodThatReturnsSomething;
@end


// when you implement a protocol the syntax will simply be
// #import "Foo.h"
// @interface Test : NSObject <Foo>
// @end
// or in the implementation file