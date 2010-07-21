/**\file		options.h
 * \author		Mao Yu
 * \date		Modified: Saturday, July 10, 2010
 * \brief		Options handling.
 */
#ifndef __OPTIONS_H__
#define __OPTIONS_H__

#include "common.h"
#include "gamma.h"

/**\brief Minimum temperature */
#define MIN_TEMP 3400
/**\brief Maximum temperature */
#define MAX_TEMP 7000

/**\brief Minimum latitude */
#define MIN_LAT   -90.0
/**\brief Maximum latitude */
#define MAX_LAT    90.0
/**\brief Minimum longitude */
#define MIN_LON  -180.0
/**\brief Maximum longitude */
#define MAX_LON   180.0
/**\brief Minimum gamma value */
#define MIN_GAMMA   0.1
/**\brief Maximum gamma value */
#define MAX_GAMMA  10.0
/**\brief Minimum transition speed */
#define MIN_SPEED     1
/**\brief Maximum transition speed */
#define MAX_SPEED  1000

/**\brief Default daytime temperature limit */
#define DEFAULT_DAY_TEMP    6500
/**\brief Default nighttime temperature limit */
#define DEFAULT_NIGHT_TEMP  3600
/**\brief Default gamma values */
#define DEFAULT_GAMMA        1.0
/**\brief Default transition speed */
#define DEFAULT_TRANSPEED   1000

/**\brief Retrieves full path of the configuration file.
 * \param buffer buffer to store the configuration file.
 * \param bufsize size of the buffer.
 */
int opt_get_config_file(char buffer[],size_t bufsize);

/**\brief Load default values for all fields.
 */
void opt_set_defaults(void);

/**\brief Sets the CRTC to apply adjustment to.
 * \param val integer value of CRTC
 */
int opt_set_crtc(int val);

/**\brief Sets additional gamma adjustment.
 * \param r red value
 * \param g green value
 * \param b blue value
 */
int opt_set_gamma(float r, float g, float b);

/**\brief Parses a string containing gamma adjustment
 * \param val string containing text in the form of R:G:B
 */
int opt_parse_gamma(char *val);

/**\brief Sets the location with latitude/longitude
 * \param lat latitude
 * \param lon longitude
 */
int opt_set_location(float lat, float lon);

/**\brief Parses a string containing location
 * \param val string containing text in the form of LAT:LON
 */
int opt_parse_location(char *val);

/**\brief Sets console mode
 * \param val 0 for GUI mode, 1 for console mode
 */
int opt_set_nogui(int val);

/**\brief Sets the method of gamma adjustment
 * \param method gamma_method_t argument
 */
int opt_set_method(gamma_method_t method);

/**\brief Parses a string of the method
 * \param val string containing either 
 *		"randr" (or "RANDR"),
 *		"vidmode" (or "VidMode"),
 *	or	"wingdi" (or "WinGDI")
 */
int opt_parse_method(char *val);

/**\brief Sets one shot mode (adjust and then exit)
 * \param onoff set to 1 to enable
 */
int opt_set_oneshot(int onoff);

/**\brief Sets transition speed
 * \param tpersec temperature per second, defaults to 100k/s
 */
int opt_set_transpeed(int tpersec);

/**\brief Sets the screen to apply adjustment to.
 * \param val integer value of the screen.
 */
int opt_set_screen(int val);

/**\brief Sets the temperatures for day/night
 * \param tday temperature for daytime (defaults to DEFAULT_DAY_TEMP)
 * \param tnight temperature for nighttime (defaults to DEFAULT_NIGHT_TEMP)
 */
int opt_set_temperatures(int tday, int tnight);

/**\brief Parse the temperatures from string
 * \param val String containing text in the form of "DAY:NIGHT"
 */
int opt_parse_temperatures(char *val);

/**\brief Sets the verbosity of the logging level.
 * \param val verbosity
 */
int opt_set_verbose(int val);

#ifdef ENABLE_IUP
/**\brief Starts GUI minimized.
 * \param val Set to 1 to start minimized
 */
int opt_set_min(int val);

/**\brief Starts GUI disabled.
 * \param val Set to 1 to start disabled
 */
int opt_set_disabled(int val);
#endif

/**\brief Retrieves CRTC */
int opt_get_crtc(void);

/**\brief Retrieves Gamma */
gamma_s opt_get_gamma(void);

/**\brief Retrieves latitude */
float opt_get_lat(void);

/**\brief Retrieves longitude */
float opt_get_lon(void);

/**\brief Retrieves no GUI mode */
int opt_get_nogui(void);

/**\brief Retrieves method */
gamma_method_t opt_get_method(void);

/**\brief Retrieves oneshot mode */
int opt_get_oneshot(void);

/**\brief Retrieves transition speed */
int opt_get_trans_speed(void);

/**\brief Retrieves screen */
int opt_get_screen(void);

/**\brief Retrieves day temperature */
int opt_get_temp_day(void);

/**\brief Retrieves night temperature */
int opt_get_temp_night(void);

/**\brief Retrieves verbosity level */
int opt_get_verbosity(void);

#ifdef ENABLE_IUP
/**\brief Retrieves start minimized status */
int opt_get_min(void);

/**\brief Retrieves start disabled status */
int opt_get_disabled(void);
#endif//ENABLE_IUP

/**\brief Writes the configuration file with current settings */
void opt_write_config(void);

#endif//__OPTIONS_H__