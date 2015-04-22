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

namespace UnitTestConstants {
  static const double pi { 3.141592653589793 };
}

class JSValueTests : public testing::Test {
 protected:
  virtual void SetUp() {
  }
  
  virtual void TearDown() {
  }
  
  JSContextGroup js_context_group;
};

TEST_F(JSValueTests, JSUndefined) {
  JSContext js_context = js_context_group.CreateContext();
  JSUndefined js_undefined = js_context.CreateUndefined();
  XCTAssertEqual("undefined", static_cast<std::string>(js_undefined));
  XCTAssertTrue(js_undefined.IsUndefined());
  XCTAssertFalse(js_undefined.IsNull());
  XCTAssertFalse(js_undefined.IsBoolean());
  XCTAssertFalse(js_undefined.IsNumber());
  XCTAssertFalse(js_undefined.IsString());
  XCTAssertFalse(js_undefined.IsObject());
}

TEST_F(JSValueTests, JSNull) {
  JSContext js_context = js_context_group.CreateContext();
  JSNull js_null = js_context.CreateNull();
  XCTAssertEqual("null", static_cast<std::string>(js_null));
  XCTAssertFalse(js_null.IsUndefined());
  XCTAssertTrue(js_null.IsNull());
  XCTAssertFalse(js_null.IsBoolean());
  XCTAssertFalse(js_null.IsNumber());
  XCTAssertFalse(js_null.IsString());
  XCTAssertFalse(js_null.IsObject());
}

TEST_F(JSValueTests, NativeNull) {
  JSContext js_context = js_context_group.CreateContext();
  JSValue js_null = js_context.CreateNativeNull();
  XCTAssertEqual("null", static_cast<std::string>(js_null));
  XCTAssertFalse(js_null.IsUndefined());
  XCTAssertTrue(js_null.IsNull());
  XCTAssertFalse(js_null.IsBoolean());
  XCTAssertFalse(js_null.IsNumber());
  XCTAssertFalse(js_null.IsString());
  XCTAssertFalse(js_null.IsObject());
  XCTAssertTrue(js_null.IsNativeNull());
}

TEST_F(JSValueTests, JSBoolean) {
  JSContext js_context = js_context_group.CreateContext();
  JSBoolean js_false = js_context.CreateBoolean(false);
  XCTAssertFalse(js_false);
  
  XCTAssertEqual("false", static_cast<std::string>(js_false));
  XCTAssertFalse(js_false.IsUndefined());
  XCTAssertFalse(js_false.IsNull());
  XCTAssertTrue(js_false.IsBoolean());
  XCTAssertFalse(js_false.IsNumber());
  XCTAssertFalse(js_false.IsString());
  XCTAssertFalse(js_false.IsObject());
  
  JSBoolean js_true = js_context.CreateBoolean(true);
  XCTAssertTrue(static_cast<bool>(js_true));
  
  XCTAssertEqual("true", static_cast<std::string>(js_true));
  XCTAssertFalse(js_true.IsUndefined());
  XCTAssertFalse(js_true.IsNull());
  XCTAssertTrue(js_true.IsBoolean());
  XCTAssertFalse(js_true.IsNumber());
  XCTAssertFalse(js_true.IsString());
  XCTAssertFalse(js_true.IsObject());
  
  JSBoolean js_boolean = js_context.CreateBoolean(true);
  XCTAssertTrue(static_cast<bool>(js_boolean));
  js_boolean = false;
  XCTAssertFalse(static_cast<bool>(js_boolean));
}

TEST_F(JSValueTests, JSNumber) {
  JSContext js_context = js_context_group.CreateContext();
  JSNumber js_double = js_context.CreateNumber(UnitTestConstants::pi);
  //XCTAssertEqualWithAccuracy(UnitTestConstants::pi, static_cast<double>(js_double), std::numeric_limits<double>::epsilon());
  ASSERT_DOUBLE_EQ(UnitTestConstants::pi, static_cast<double>(js_double));
  
  XCTAssertEqual("3.141592653589793", static_cast<std::string>(js_double));
  XCTAssertFalse(js_double.IsUndefined());
  XCTAssertFalse(js_double.IsNull());
  XCTAssertFalse(js_double.IsBoolean());
  XCTAssertTrue(js_double.IsNumber());
  XCTAssertFalse(js_double.IsString());
  XCTAssertFalse(js_double.IsObject());
  
  const int32_t int32_value = 42;
  JSNumber js_int32 = js_context.CreateNumber(int32_value);
  XCTAssertEqual(int32_value, static_cast<int32_t>(js_int32));
  
  XCTAssertEqual("42", static_cast<std::string>(js_int32));
  XCTAssertFalse(js_int32.IsUndefined());
  XCTAssertFalse(js_int32.IsNull());
  XCTAssertFalse(js_int32.IsBoolean());
  XCTAssertTrue(js_int32.IsNumber());
  XCTAssertFalse(js_int32.IsString());
  XCTAssertFalse(js_int32.IsObject());

  const uint32_t uint32_value = 42;
  JSNumber js_uint32 = js_context.CreateNumber(uint32_value);
  XCTAssertEqual(uint32_value, static_cast<uint32_t>(js_uint32));
  
  XCTAssertEqual("42", static_cast<std::string>(js_uint32));
  XCTAssertFalse(js_uint32.IsUndefined());
  XCTAssertFalse(js_uint32.IsNull());
  XCTAssertFalse(js_uint32.IsBoolean());
  XCTAssertTrue(js_uint32.IsNumber());
  XCTAssertFalse(js_uint32.IsString());
  XCTAssertFalse(js_uint32.IsObject());

  auto js_pi_value  = js_context.JSEvaluateScript("Math.PI");
  //XCTAssertEqualWithAccuracy(UnitTestConstants::pi, static_cast<double>(js_pi_value), std::numeric_limits<double>::epsilon());
  ASSERT_DOUBLE_EQ(UnitTestConstants::pi, static_cast<double>(js_pi_value));

  auto js_result  = js_context.JSEvaluateScript("21 / 7");
  XCTAssertEqual(3, static_cast<int32_t>(js_result));

  js_result  = js_context.JSEvaluateScript("21 / 7");
  XCTAssertEqual(3, static_cast<uint32_t>(js_result));
}

TEST_F(JSValueTests, ToJSONString) {
  JSContext js_context = js_context_group.CreateContext();
  JSUndefined js_undefined = js_context.CreateUndefined();
  JSString js_undefined_json = js_undefined.ToJSONString();
  //std::clog << "MDL: js_undefined_json = " << js_undefined_json << std::endl;
  XCTAssertEqual(0, js_undefined_json.length());
  
  JSNull js_null = js_context.CreateNull();
  JSString js_null_json = js_null.ToJSONString();
  std::clog << "MDL: js_null_json = " << js_null_json << std::endl;
  XCTAssertEqual("null", js_null_json);
  
  JSBoolean js_false = js_context.CreateBoolean(false);
  JSString js_false_sjon = js_false.ToJSONString();
  //std::clog << "MDL: js_false_sjon = " << js_false_sjon << std::endl;
  XCTAssertEqual("false", js_false_sjon);

  JSBoolean js_true = js_context.CreateBoolean(true);
  JSString js_true_sjon = js_true.ToJSONString();
  //std::clog << "MDL: js_true_sjon = " << js_true_sjon << std::endl;
  XCTAssertEqual("true", js_true_sjon);
  
  JSNumber js_double = js_context.CreateNumber(UnitTestConstants::pi);
  JSString js_double_sjon = js_double.ToJSONString();
  //std::clog << "MDL: js_double_sjon = " << js_double_sjon << std::endl;
  XCTAssertEqual("3.141592653589793", js_double_sjon);

  JSNumber js_int32 = js_context.CreateNumber(int32_t(42));
  JSString js_int32_sjon = js_int32.ToJSONString();
  //std::clog << "MDL: js_int32_sjon = " << js_int32_sjon << std::endl;
  XCTAssertEqual("42", js_int32_sjon);

  JSNumber js_uint32 = js_context.CreateNumber(uint32_t(42));
  JSString js_uint32_sjon = js_uint32.ToJSONString();
  //std::clog << "MDL: js_uint32_sjon = " << js_uint32_sjon << std::endl;
  XCTAssertEqual("42", js_uint32_sjon);
}

TEST_F(JSValueTests, String) {
  JSContext js_context = js_context_group.CreateContext();
  JSValue js_value = js_context.CreateString("hello, world");
  XCTAssertEqual("hello, world", static_cast<std::string>(js_value));
  
  XCTAssertFalse(js_value.IsUndefined());
  XCTAssertFalse(js_value.IsNull());
  XCTAssertFalse(js_value.IsBoolean());
  XCTAssertFalse(js_value.IsNumber());
  XCTAssertTrue(js_value.IsString());
  XCTAssertFalse(js_value.IsObject());
  
  JSString js_string = static_cast<JSString>(js_value);
  XCTAssertEqual("hello, world", js_string);
  
  auto js_result  = js_context.JSEvaluateScript("'hello, JavaScript'");
  XCTAssertEqual("hello, JavaScript", static_cast<std::string>(js_result));
}

TEST_F(JSValueTests, CopyingValuesBetweenContexts) {
  JSContext js_context_1 = js_context_group.CreateContext();
  JSValue js_value_1 = js_context_1.CreateString("foo");
  XCTAssertEqual("foo", static_cast<std::string>(js_value_1));
  
  JSContext js_context_2 = js_context_group.CreateContext();
  JSValue js_value_2 = js_context_1.CreateString("bar");
  XCTAssertEqual("bar", static_cast<std::string>(js_value_2));
  
  XCTAssertNotEqual(js_context_1, js_context_2);
  XCTAssertEqual(js_context_1.get_context_group(), js_context_2.get_context_group());
  js_value_2 = js_value_1;
  XCTAssertEqual("foo", static_cast<std::string>(js_value_2));
  
  // Show that copying JSValues between different JSContextGroups throws a
  // std::runtime_error exception.
  JSContextGroup js_context_group_2;

  JSContext js_context_3 = js_context_group_2.CreateContext();
  JSValue js_value_3 = js_context_3.CreateString("baz");
  XCTAssertEqual("baz", static_cast<std::string>(js_value_3));

  JSContext js_context_4 = js_context_group_2.CreateContext();
  JSValue js_value_4 = js_context_4.CreateString("foobar");
  XCTAssertEqual("foobar", static_cast<std::string>(js_value_4));

  XCTAssertNotEqual(js_context_3, js_context_4);
  XCTAssertEqual(js_context_3.get_context_group(), js_context_4.get_context_group());
  
  XCTAssertNotEqual(js_context_1.get_context_group(), js_context_3.get_context_group());
  XCTAssertNotEqual(js_context_1.get_context_group(), js_context_4.get_context_group());

  XCTAssertNotEqual(js_context_2.get_context_group(), js_context_3.get_context_group());
  XCTAssertNotEqual(js_context_2.get_context_group(), js_context_4.get_context_group());

  // You can't copy JSValue's between different JSContextGroups.
  ASSERT_THROW(js_value_3 = js_value_1, std::runtime_error);
}
