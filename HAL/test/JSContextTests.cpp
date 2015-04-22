/**
 * HAL
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "HAL/HAL.hpp"

#include "gtest/gtest.h"

#define XCTAssertEqual    ASSERT_EQ
#define XCTAssertNotEqual ASSERT_NE
#define XCTAssertTrue     ASSERT_TRUE
#define XCTAssertFalse    ASSERT_FALSE

using namespace HAL;

class JSContextTests : public testing::Test {
 protected:
  virtual void SetUp() {
  }
  
  virtual void TearDown() {
  }
  
  JSContextGroup js_context_group;
};

TEST_F(JSContextTests, JSEvaluateScript) {
  JSContext js_context = js_context_group.CreateContext();
  JSValue js_value     = js_context.JSEvaluateScript("'Hello, world.'");
  XCTAssertEqual("Hello, world.", static_cast<std::string>(js_value));
}

TEST_F(JSContextTests, JSEvaluateScriptWithError) {
  try {
    JSContext js_context = js_context_group.CreateContext();
    JSValue js_value = js_context.JSEvaluateScript("}@!]}", js_context.get_global_object(), "app.js", 123);
    XCTAssertTrue(false);
  } catch (const HAL::detail::js_runtime_error& e) {
    XCTAssertEqual("SyntaxError", e.js_name());
    XCTAssertEqual("app.js", e.js_filename());
    XCTAssertEqual(123, e.js_linenumber());
  } catch (...) {
    XCTAssertTrue(false);
  }
}

TEST_F(JSContextTests, JSContext) {
  JSContext js_context_1 = js_context_group.CreateContext();
  JSContext js_context_2 = js_context_group.CreateContext();
  XCTAssertNotEqual(js_context_1, js_context_2);
  
  // Test copy constructor.
  JSContext js_context_3(js_context_1);
  XCTAssertEqual(js_context_1, js_context_3);
  
  // Test copy assignment.
  JSContext js_context_4 = js_context_1;
  XCTAssertEqual(js_context_1, js_context_4);
  
  // Test move constructor.
  JSContext js_context_5(js_context_group.CreateContext());
  
  // Test unified assignment operator
  JSContext js_context_6 = js_context_1;
  XCTAssertEqual(js_context_1, js_context_6);
  
  // Test creating JSContexts in different groups.
  JSContext js_context_7 = js_context_group.CreateContext();
  JSContext js_context_8 = js_context_group.CreateContext();
  XCTAssertNotEqual(js_context_7, js_context_8);
  
  // Test copy constructor.
  JSContext js_context_9(js_context_7);
  XCTAssertEqual(js_context_7, js_context_9);
  
  // Test copy assignment.
  JSContext js_context_10 = js_context_7;
  XCTAssertEqual(js_context_7, js_context_10);
  
  // Test move constructor.
  JSContext js_context_11(js_context_group.CreateContext());
  
  // Test unified assignment operator
  JSContext js_context_12 = js_context_7;
  XCTAssertEqual(js_context_7, js_context_12);
}
