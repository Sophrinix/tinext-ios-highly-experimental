/**
 * TitaniumKit Titanium.Geolocation
 *
 * Copyright (c) 2015 by Appcelerator, Inc. All Rights Reserved.
 * Licensed under the terms of the Apache Public License.
 * Please see the LICENSE included with this distribution for details.
 */

#ifndef _TITANIUM_GEOLOCATION_HPP_
#define _TITANIUM_GEOLOCATION_HPP_

#include "Titanium/Module.hpp"
#include "Titanium/Geolocation/Constants.hpp"

namespace Titanium
{
	using namespace HAL;

	/*!
	  @class
	  @discussion This is the Titanium Geolocation Module.
	  See http://docs.appcelerator.com/titanium/latest/#!/api/Titanium.Geolocation
	*/
	class TITANIUMKIT_EXPORT GeolocationModule : public Module, public JSExport<GeolocationModule>
	{

	public:

		TITANIUM_PROPERTY_READONLY_DEF(ACCURACY_BEST);
		TITANIUM_PROPERTY_READONLY_DEF(ACCURACY_BEST_FOR_NAVIGATION);
		TITANIUM_PROPERTY_READONLY_DEF(ACCURACY_HUNDRED_METERS);
		TITANIUM_PROPERTY_READONLY_DEF(ACCURACY_KILOMETER);
		TITANIUM_PROPERTY_READONLY_DEF(ACCURACY_NEAREST_TEN_METERS);
		TITANIUM_PROPERTY_READONLY_DEF(ACCURACY_THREE_KILOMETERS);
		TITANIUM_PROPERTY_READONLY_DEF(ACCURACY_HIGH);
		TITANIUM_PROPERTY_READONLY_DEF(ACCURACY_LOW);

		TITANIUM_PROPERTY_READONLY_DEF(ACTIVITYTYPE_AUTOMOTIVE_NAVIGATION);
		TITANIUM_PROPERTY_READONLY_DEF(ACTIVITYTYPE_FITNESS);
		TITANIUM_PROPERTY_READONLY_DEF(ACTIVITYTYPE_OTHER);
		TITANIUM_PROPERTY_READONLY_DEF(ACTIVITYTYPE_OTHER_NAVIGATION);

		TITANIUM_PROPERTY_READONLY_DEF(AUTHORIZATION_ALWAYS);
		TITANIUM_PROPERTY_READONLY_DEF(AUTHORIZATION_AUTHORIZED);
		TITANIUM_PROPERTY_READONLY_DEF(AUTHORIZATION_DENIED);
		TITANIUM_PROPERTY_READONLY_DEF(AUTHORIZATION_RESTRICTED);
		TITANIUM_PROPERTY_READONLY_DEF(AUTHORIZATION_UNKNOWN);
		TITANIUM_PROPERTY_READONLY_DEF(AUTHORIZATION_WHEN_IN_USE);

		TITANIUM_PROPERTY_READONLY_DEF(ERROR_DENIED);
		TITANIUM_PROPERTY_READONLY_DEF(ERROR_HEADING_FAILURE);
		TITANIUM_PROPERTY_READONLY_DEF(ERROR_LOCATION_UNKNOWN);
		TITANIUM_PROPERTY_READONLY_DEF(ERROR_NETWORK);
		TITANIUM_PROPERTY_READONLY_DEF(ERROR_REGION_MONITORING_DELAYED);
		TITANIUM_PROPERTY_READONLY_DEF(ERROR_REGION_MONITORING_DENIED);
		TITANIUM_PROPERTY_READONLY_DEF(ERROR_REGION_MONITORING_FAILURE);
		TITANIUM_PROPERTY_READONLY_DEF(ERROR_TIMEOUT);

		TITANIUM_PROPERTY_READONLY_DEF(PROVIDER_GPS);
		TITANIUM_PROPERTY_READONLY_DEF(PROVIDER_NETWORK);
		TITANIUM_PROPERTY_READONLY_DEF(PROVIDER_PASSIVE);
		
		/*!
		  @property
		  @abstract accuracy
		  @discussion Specifies the requested accuracy for location updates.
		*/
		TITANIUM_PROPERTY_IMPL_DEF(Geolocation::ACCURACY, accuracy);

		/*!
		  @property
		  @abstract activityType
		  @discussion The type of user activity to be associated with the location updates.
		*/
		TITANIUM_PROPERTY_IMPL_DEF(Geolocation::ACTIVITYTYPE, activityType);

		/*!
		  @property
		  @abstract distanceFilter
		  @discussion The minimum change of position (in meters) before a 'location' event is fired.
		*/
		TITANIUM_PROPERTY_IMPL_DEF(double, distanceFilter);

		/*!
		  @property
		  @abstract headingFilter
		  @discussion Minimum heading change (in degrees) before a heading event is fired.
		*/
		TITANIUM_PROPERTY_IMPL_DEF(double, headingFilter);

		/*!
		  @property
		  @abstract hasCompass
		  @discussion Indicates whether the current device supports a compass.
		*/
		TITANIUM_PROPERTY_IMPL_DEF(bool, hasCompass);

		/*!
		  @property
		  @abstract locationServicesAuthorization
		  @discussion Gets the value of the locationServicesAuthorization property.
		*/
		TITANIUM_PROPERTY_IMPL_DEF(Geolocation::AUTHORIZATION, locationServicesAuthorization);

		/*!
		  @property
		  @abstract locationServicesEnabled
		  @discussion Indicates if the user has enabled or disabled location services for the device (not the application).
		*/
		TITANIUM_PROPERTY_IMPL_DEF(bool, locationServicesEnabled);

		/*!
		  @property
		  @abstract lastGeolocation
		  @discussion JSON representation of the last geolocation received.
		*/
		virtual const JSObject& get_lastGeolocation() const TITANIUM_NOEXCEPT;
		virtual void set_lastGeolocation(const JSObject& lastGeolocation) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract forwardGeocoder
		  @discussion Resolves an address to a location.
		*/
		virtual void forwardGeocoder(const std::string& address, JSObject callback) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract getCurrentHeading
		  @discussion Retrieves the current compass heading.
		*/
		virtual void getCurrentHeading(JSObject callback) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract getCurrentPosition
		  @discussion Retrieves the last known location from the device.
		*/
		virtual void getCurrentPosition(JSObject callback) TITANIUM_NOEXCEPT;

		/*!
		  @method
		  @abstract reverseGeocoder
		  @discussion Tries to resolve a location to an address.
		*/
		virtual void reverseGeocoder(const double& latitude, const double& longitude, JSObject callback) TITANIUM_NOEXCEPT;

		GeolocationModule(const JSContext&) TITANIUM_NOEXCEPT;
		virtual ~GeolocationModule() = default;
		GeolocationModule(const GeolocationModule&) = default;
		GeolocationModule& operator=(const GeolocationModule&) = default;
#ifdef TITANIUM_MOVE_CTOR_AND_ASSIGN_DEFAULT_ENABLE
		GeolocationModule(GeolocationModule&&)                 = default;
		GeolocationModule& operator=(GeolocationModule&&)      = default;
#endif

		static void JSExportInitialize();

		TITANIUM_PROPERTY_DEF(accuracy);
		TITANIUM_PROPERTY_DEF(activityType);
		TITANIUM_PROPERTY_DEF(distanceFilter);
		TITANIUM_PROPERTY_DEF(headingFilter);
		TITANIUM_PROPERTY_READONLY_DEF(hasCompass);
		TITANIUM_PROPERTY_DEF(locationServicesAuthorization);
		TITANIUM_PROPERTY_READONLY_DEF(locationServicesEnabled);
		TITANIUM_PROPERTY_READONLY_DEF(lastGeolocation);

		TITANIUM_FUNCTION_DEF(forwardGeocoder);
		TITANIUM_FUNCTION_DEF(getCurrentHeading);
		TITANIUM_FUNCTION_DEF(getCurrentPosition);
		TITANIUM_FUNCTION_DEF(reverseGeocoder);
		TITANIUM_FUNCTION_DEF(getAccuracy);
		TITANIUM_FUNCTION_DEF(setAccuracy);
		TITANIUM_FUNCTION_DEF(getActivityType);
		TITANIUM_FUNCTION_DEF(setActivityType);
		TITANIUM_FUNCTION_DEF(getDistanceFilter);
		TITANIUM_FUNCTION_DEF(setDistanceFilter);
		TITANIUM_FUNCTION_DEF(getHeadingFilter);
		TITANIUM_FUNCTION_DEF(setHeadingFilter);
		TITANIUM_FUNCTION_DEF(getHasCompass);
		TITANIUM_FUNCTION_DEF(setLocationServicesAuthorization);
		TITANIUM_FUNCTION_DEF(getLocationServicesAuthorization);
		TITANIUM_FUNCTION_DEF(getLocationServicesEnabled);
		TITANIUM_FUNCTION_DEF(getLastGeolocation);

		protected:
			JSValue accuracy_best__;
			JSValue accuracy_best_for_navigation__;
			JSValue accuracy_hundred_meters__;
			JSValue accuracy_kilometer__;
			JSValue accuracy_nearest_ten_meters__;
			JSValue accuracy_three_kilometers__;
			JSValue accuracy_high__;
			JSValue accuracy_low__;
			JSValue activitytype_automotive_navigation__;
			JSValue activitytype_fitness__;
			JSValue activitytype_other__;
			JSValue activitytype_other_navigation__;
			JSValue authorization_always__;
			JSValue authorization_authorized__;
			JSValue authorization_denied__;
			JSValue authorization_restricted__;
			JSValue authorization_unknown__;
			JSValue authorization_when_in_use__;
			JSValue error_denied__;
			JSValue error_heading_failure__;
			JSValue error_location_unknown__;
			JSValue error_network__;
			JSValue error_region_monitoring_delayed__;
			JSValue error_region_monitoring_denied__;
			JSValue error_region_monitoring_failure__;
			JSValue error_timeout__;
			JSValue provider_gps__;
			JSValue provider_network__;
			JSValue provider_passive__;
			Geolocation::ACCURACY accuracy__;
			Geolocation::ACTIVITYTYPE activityType__;
			double distanceFilter__;
			double headingFilter__;
			bool hasCompass__;
			Geolocation::AUTHORIZATION locationServicesAuthorization__;
			bool locationServicesEnabled__;
			JSObject lastGeolocation__;
			JSObject heading__;
	};
} // namespace Titanium
#endif // _TITANIUM_GEOLOCATION_HPP_