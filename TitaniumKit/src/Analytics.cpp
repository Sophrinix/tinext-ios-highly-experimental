/**
 * Titanium.Analytics for Windows
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include <string>
#include "Titanium/Analytics.hpp"
#include "Titanium/analytics_js.hpp"

namespace Titanium
{

    Analytics::Analytics(const JSContext& js_context) TITANIUM_NOEXCEPT
	  : Module(js_context),
		ti_analytics__(js_context.CreateObject())
    {
		TITANIUM_LOG_DEBUG("Analytics:: ctor ", this);
    }

	void Analytics::postCallAsConstructor(const JSContext& js_context, const std::vector<JSValue>& arguments) {
		HAL_LOG_DEBUG("Analytics:: postCallAsConstructor ", this);
	}

	bool Analytics::loadJS()
	{
		if (ti_analytics__.HasProperty("lastEvent") && ti_analytics__.HasProperty("featureEvent") && ti_analytics__.HasProperty("navEvent")) {
			return true;
		}

		JSContext context = get_context();
		auto export_object = context.CreateObject();
		export_object.SetProperty("global", context.get_global_object());

		context.JSEvaluateScript(analytics_js, export_object);

		if (export_object.HasProperty("exports")) {
			ti_analytics__ = static_cast<JSObject>(export_object.GetProperty("exports"));
		} else {
			return false;
		}
		return true;
	}

	void Analytics::JSExportInitialize() {
		JSExport<Analytics>::SetClassVersion(1);
		JSExport<Analytics>::SetParent(JSExport<Module>::Class());

		TITANIUM_ADD_PROPERTY_READONLY(Analytics, lastEvent);
		TITANIUM_ADD_FUNCTION(Analytics, featureEvent);
		TITANIUM_ADD_FUNCTION(Analytics, navEvent);
		TITANIUM_ADD_FUNCTION(Analytics, getLastEvent);
	}

	JSObject Analytics::GetStaticObject(const JSContext& js_context) TITANIUM_NOEXCEPT
	{
		JSValue Titanium_property = js_context.get_global_object().GetProperty("Titanium");
		TITANIUM_ASSERT(Titanium_property.IsObject());  // precondition
		JSObject Titanium = static_cast<JSObject>(Titanium_property);

		JSValue Object_property = Titanium.GetProperty("Analytics");
		TITANIUM_ASSERT(Object_property.IsObject());  // precondition
		return static_cast<JSObject>(Object_property);
	}

	TITANIUM_PROPERTY_GETTER(Analytics, lastEvent)
	{
//		// lazy loading
//		const auto loaded = loadJS();
//		if (loaded) {
//			return ti_analytics__.GetProperty("lastEvent");
//		} else {
//			TITANIUM_LOG_ERROR("Failed to execute Analytics.lastEvent");
			return get_context().CreateNull();
//		}
	}

	TITANIUM_FUNCTION(Analytics, featureEvent)
	{
		const auto js_context = this_object.get_context();
		const auto analytics = GetStaticObject(js_context).GetPrivate<Analytics>();

		// lazy loading
		const auto loaded = analytics->loadJS();
		if (loaded) {
			auto func = analytics->getTiObject().GetProperty("featureEvent");
			return static_cast<JSObject>(func)(arguments, this_object);
		} else {
			TITANIUM_LOG_ERROR("Failed to execute Database.featureEvent");
			return this_object.get_context().CreateNull();
		}
	}

	TITANIUM_FUNCTION(Analytics, navEvent)
	{
		const auto js_context = this_object.get_context();
		const auto analytics = GetStaticObject(js_context).GetPrivate<Analytics>();

		// lazy loading
		const auto loaded = analytics->loadJS();
		if (loaded) {
			auto func = analytics->getTiObject().GetProperty("navEvent");
			return static_cast<JSObject>(func)(arguments, this_object);
		} else {
			TITANIUM_LOG_ERROR("Failed to execute Database.navEvent");
			return get_context().CreateNull();
		}
	}

	TITANIUM_FUNCTION_AS_GETTER(Analytics, getLastEvent, lastEvent);

} // namespace Titanium