//
//  MacrosAssert.h
//  Hello
//
//  Created by ccf on 16/5/31.
//
//

#ifndef MacrosAssert_h
#define MacrosAssert_h

#define CC_RETURN_IF(condition)                 if(condition) return
#define CC_RETURN_VALUE_IF(condition,value)     if(condition) return value
#define CC_RETURN_IF_ASSERT_FAIL(cond)          CC_ASSERT(cond);  if(!(cond)) return
#define CC_RETURN_VALUE_IF_ASSERT_FAIL(cond,value)          CC_ASSERT(cond);  if(!(cond)) return value

#endif /* MacrosAssert_h */
