/**
 * TitaniumKit
 *
 * Copyright (c) 2014 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_UI_TEXTAREA_HPP_
#define _TITANIUM_UI_TEXTAREA_HPP_

#include "Titanium/UI/View.hpp"
#include "Titanium/UI/Constants.hpp"

namespace Titanium
{
	namespace UI
	{
		using namespace HAL;

		/*!
		  @class

		  @discussion This is the Titanium.UI.TextArea module.

		  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.UI.TextArea
		*/
		class TITANIUMKIT_EXPORT TextArea : public View, public JSExport<TextArea>
		{
		public:
			/*!
			  @method

			  @abstract autoLink : Number

			  @discussion Automatically convert text to clickable
			  links. Multiple autolink values can be combined with a bitwise
			  OR. For example:

			  textArea.autoLink = AUTOLINK_MAP_ADDRESSES|AUTOLINK_PHONE_NUMBERS;
			*/
			virtual std::unordered_set<AUTOLINK> get_autoLink() const TITANIUM_NOEXCEPT final;
			virtual void set_autoLink(const std::unordered_set<AUTOLINK>& autoLink) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract  keyboardType : Number

			  @discussion Keyboard type to display when this text field is
			  focused. When asking for a specific kind of user input, such as a
			  phone number or email address, you should always specify the
			  appropriate keyboard type.
			*/
			virtual KEYBOARD get_keyboardType() const TITANIUM_NOEXCEPT final;
			virtual void set_keyboardType(const KEYBOARD& keyboardType) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract returnKeyType : Number

			  @discussion Specifies the text to display on the keyboard Return key when this text area is focused.
			*/
			virtual RETURNKEY get_returnKeyType() const TITANIUM_NOEXCEPT final;
			virtual void set_returnKeyType(const RETURNKEY& returnKeyType) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract textAlign : String/Number

			  @discussion Text alignment within this text field.
			*/
			virtual TEXT_ALIGNMENT get_textAlign() const TITANIUM_NOEXCEPT final;
			virtual void set_textAlign(const TEXT_ALIGNMENT& textAlign) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract autocapitalization : Number

			  @discussion Determines how text is capitalized during typing.
			*/
			virtual TEXT_AUTOCAPITALIZATION get_autocapitalization() const TITANIUM_NOEXCEPT final;
			virtual void set_autocapitalization(const TEXT_AUTOCAPITALIZATION& autocapitalization) TITANIUM_NOEXCEPT;

			/*!
			  @method

			  @abstract verticalAlign : Number/String

			  @discussion Vertical alignment within this text field.
			*/
			virtual TEXT_VERTICAL_ALIGNMENT get_verticalAlign() const TITANIUM_NOEXCEPT final;
			virtual void set_verticalAlign(const TEXT_VERTICAL_ALIGNMENT& verticalAlign) TITANIUM_NOEXCEPT;

			TextArea(const JSContext&) TITANIUM_NOEXCEPT;

			virtual ~TextArea() = default;
			TextArea(const TextArea&) = default;
			TextArea& operator=(const TextArea&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
			TextArea(TextArea&&) = default;
			TextArea& operator=(TextArea&&) = default;
#endif

			// TODO: The following functions can automatically be generated
			// from the YAML API docs.
			static void JSExportInitialize();

			TITANIUM_PROPERTY_DEF(autoLink);
			TITANIUM_PROPERTY_DEF(keyboardType);
			TITANIUM_PROPERTY_DEF(returnKeyType);
			TITANIUM_PROPERTY_DEF(textAlign);
			TITANIUM_PROPERTY_DEF(autocapitalization);
			TITANIUM_PROPERTY_DEF(verticalAlign);

		private:
			std::unordered_set<AUTOLINK> autoLink__;
			KEYBOARD keyboardType__;
			RETURNKEY returnKeyType__;
			TEXT_ALIGNMENT textAlign__;
			TEXT_AUTOCAPITALIZATION autocapitalization__;
			TEXT_VERTICAL_ALIGNMENT verticalAlign__;
		};
	} // namespace UI
}  // namespace Titanium

#endif  // _TITANIUM_UI_TEXTAREA_HPP_
