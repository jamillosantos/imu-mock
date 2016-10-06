/**
 * @author J. Santos <jamillo@gmail.com>
 * @date November 25, 2015
 **/

#ifndef VISUALIZER_DEFINITIONS_H
#define VISUALIZER_DEFINITIONS_H

#include "math.h"

#ifndef __FILENAME__
#define __FILENAME__ __FILE__
#endif

#ifdef DEBUG
#define VERBOSE_HEADER "[VERBOSE] " << __FILENAME__ << ":" << __LINE__ << ") "
#define VERBOSE(x) std::cout << VERBOSE_HEADER << x << std::endl
#define VERBOSENEL(x) std::cout << VERBOSE_HEADER << x
#define VERBOSEDATA(d, s) Channel::dumpData(d, s)
#define VERBOSEB(x) std::cout << x << std::endl
#define VERBOSEBNEL(x) std::cout << x
#else
#define VERBOSE_HEADER
#define VERBOSE(x)
#define VERBOSENEL(x)
#define VERBOSEDATA(d, s)
#define VERBOSEB(x)
#define VERBOSEBNEL(x)
#endif

#define ERROR_HEADER "[ERROR] " << __FILENAME__ << ":" << __LINE__ << ") "
#define ERROR(x) std::cout << VERBOSE_HEADER << x << std::endl
#define ERRORNEL(x) std::cout << VERBOSE_HEADER << x
#define ERRORB(x) std::cout << x << std::endl
#define ERRORBNEL(x) std::cout << x

#define DEG2RAD (M_PI / 180.0)
#define RAD2DEG (180.0 / M_PI)

#define D2R(a) ((a) * DEG2RAD)
#define R2D(a) ((a) * RAD2DEG)

#endif //VISUALIZER_DEFINITIONS_H
