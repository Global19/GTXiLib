//
// Copyright 2019 Google Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import <Foundation/Foundation.h>

#import "GTXError.h"

typedef void(^GTXReportHandler)(GTXError *error);

/**
 *  A reporting class for keeping track of (unique) errors generated by GTX continuous mode.
 */
@interface GTXReport : NSObject <NSCopying>

/**
 *  Add the given set of @c errors to the report by deduping them among themselves and errors
 *  already in the report.
 */
- (void)addByDeDupingErrors:(NSArray<GTXError *> *)errors;

/**
 *  Iterates through all the (unique) errors currently in the report.
 */
- (void)forEachError:(GTXReportHandler)handler;

@end
