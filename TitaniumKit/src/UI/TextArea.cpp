/**
 * TitaniumKit
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#include "Titanium/UI/TextArea.hpp"
#include <type_traits>

namespace Titanium
{
	namespace UI
	{
		TextArea::TextArea(const JSContext& js_context) TITANIUM_NOEXCEPT
		    : View(js_context),
		      autoLink__({AUTOLINK::NONE}),
		      returnKeyType__(RETURNKEY::DEFAULT),
		      textAlign__(TEXT_ALIGNMENT::LEFT),
		      autocapitalization__(TEXT_AUTOCAPITALIZATION::NONE),
		      verticalAlign__(TEXT_VERTICAL_ALIGNMENT::CENTER)
		{
		}

		std::unordered_set<AUTOLINK> TextArea::get_autoLink() const TITANIUM_NOEXCEPT
		{
			return autoLink__;
		}

		void TextArea::set_autoLink(const std::unordered_set<AUTOLINK>& autoLink) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TextArea::set_autoLink: Unimplemented");
		}

		KEYBOARD TextArea::get_keyboardType() const TITANIUM_NOEXCEPT
		{
			return keyboardType__;
		}

		void TextArea::set_keyboardType(const KEYBOARD& keyboardType) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TextArea::set_keyboardType: Unimplemented");
		}

		RETURNKEY TextArea::get_returnKeyType() const TITANIUM_NOEXCEPT
		{
			return returnKeyType__;
		}

		void TextArea::set_returnKeyType(const RETURNKEY& keyboardType) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TextArea::get_returnKeyType: Unimplemented");
		}

		TEXT_ALIGNMENT TextArea::get_textAlign() const TITANIUM_NOEXCEPT
		{
			return textAlign__;
		}

		void TextArea::set_textAlign(const TEXT_ALIGNMENT& textAlign) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TextArea::set_textAlign: Unimplemented");
		}

		TEXT_AUTOCAPITALIZATION TextArea::get_autocapitalization() const TITANIUM_NOEXCEPT
		{
			return autocapitalization__;
		}

		void TextArea::set_autocapitalization(const TEXT_AUTOCAPITALIZATION& textAlign) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TextArea::set_autocapitalization: Unimplemented");
		}

		TEXT_VERTICAL_ALIGNMENT TextArea::get_verticalAlign() const TITANIUM_NOEXCEPT
		{
			return verticalAlign__;
		}

		void TextArea::set_verticalAlign(const TEXT_VERTICAL_ALIGNMENT& verticalAlign) TITANIUM_NOEXCEPT
		{
			TITANIUM_LOG_WARN("TextArea::set_verticalAlign: Unimplemented");
		}

		// TODO: The following functions can automatically be generated from
		// the YAML API docs.

		void TextArea::JSExportInitialize()
		{
			JSExport<TextArea>::SetClassVersion(1);
			JSExport<TextArea>::SetParent(JSExport<View>::Class());
			TITANIUM_ADD_PROPERTY(TextArea, autoLink);
			TITANIUM_ADD_PROPERTY(TextArea, keyboardType);
			TITANIUM_ADD_PROPERTY(TextArea, returnKeyType);
			TITANIUM_ADD_PROPERTY(TextArea, textAlign);
			TITANIUM_ADD_PROPERTY(TextArea, autocapitalization);
			TITANIUM_ADD_PROPERTY(TextArea, verticalAlign);
		}

		TITANIUM_PROPERTY_GETTER(TextArea, autoLink)
		{
			return get_context().CreateNumber(Constants::to_underlying_type(autoLink__));
		}

		TITANIUM_PROPERTY_SETTER(TextArea, autoLink)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			autoLink__ = Constants::to_AUTOLINK(static_cast<std::underlying_type<AUTOLINK>::type>(argument));
			set_autoLink(autoLink__);
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextArea, keyboardType)
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<KEYBOARD>::type>(get_keyboardType()));
		}

		TITANIUM_PROPERTY_SETTER(TextArea, keyboardType)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			keyboardType__ = Constants::to_KEYBOARD(static_cast<std::underlying_type<KEYBOARD>::type>(argument));
			set_keyboardType(keyboardType__);
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextArea, returnKeyType)
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<RETURNKEY>::type>(get_returnKeyType()));
		}

		TITANIUM_PROPERTY_SETTER(TextArea, returnKeyType)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			returnKeyType__ = Constants::to_RETURNKEY(static_cast<std::underlying_type<RETURNKEY>::type>(argument));
			set_returnKeyType(returnKeyType__);
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextArea, textAlign)
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<TEXT_ALIGNMENT>::type>(get_textAlign()));
		}

		TITANIUM_PROPERTY_SETTER(TextArea, textAlign)
		{
			bool result = false;
			if (argument.IsNumber()) {
				textAlign__ = Constants::to_TEXT_ALIGNMENT(static_cast<std::underlying_type<TEXT_ALIGNMENT>::type>(argument));
				set_textAlign(textAlign__);
				result = true;
			} else if (argument.IsString()) {
				textAlign__ = Constants::to_TEXT_ALIGNMENT(static_cast<std::string>(argument));
				set_textAlign(textAlign__);
				result = true;
			}

			return result;
		}

		TITANIUM_PROPERTY_GETTER(TextArea, autocapitalization)
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<TEXT_AUTOCAPITALIZATION>::type>(get_autocapitalization()));
		}

		TITANIUM_PROPERTY_SETTER(TextArea, autocapitalization)
		{
			TITANIUM_ASSERT(argument.IsNumber());
			autocapitalization__ = Constants::to_TEXT_AUTOCAPITALIZATION(static_cast<std::underlying_type<TEXT_AUTOCAPITALIZATION>::type>(argument));
			set_autocapitalization(autocapitalization__);
			return true;
		}

		TITANIUM_PROPERTY_GETTER(TextArea, verticalAlign)
		{
			return get_context().CreateNumber(static_cast<std::underlying_type<TEXT_VERTICAL_ALIGNMENT>::type>(get_verticalAlign()));
		}

		TITANIUM_PROPERTY_SETTER(TextArea, verticalAlign)
		{
			bool result = false;
			if (argument.IsNumber()) {
				verticalAlign__ = Constants::to_TEXT_VERTICAL_ALIGNMENT(static_cast<std::underlying_type<TEXT_VERTICAL_ALIGNMENT>::type>(argument));
				set_verticalAlign(verticalAlign__);
				result = true;
			} else if (argument.IsString()) {
				verticalAlign__ = Constants::to_TEXT_VERTICAL_ALIGNMENT(static_cast<std::string>(argument));
				set_verticalAlign(verticalAlign__);
				result = true;
			}

			return result;
		}
	} // namespace UI
}  // namespace Titanium
