/* Complete the http_to_str function.
 * Given the enum defined in http.h,
 * it should return a hard-coded string (char *)
 * with the human-readable version of the HTTP status code:
 *
 * HTTP_BAD_REQUEST: "400 Bad Request"
 * HTTP_UNAUTHORIZED: "401 Unauthorized"
 * HTTP_NOT_FOUND: "404 Not Found"
 * HTTP_TEAPOT: "418 I AM A TEAPOT!"
 * HTTP_INTERNAL_SERVER_ERROR: "500 Internal Server Error"
 *
 * If the status code is not one of the above,
 * return "Unknown HTTP status code".
 */
#include "http.h"

char *http_to_str(HttpErrorCode code) {
    switch (code) {
        case HTTP_BAD_REQUEST:
            return "400 Bad Request";
        case HTTP_UNAUTHORIZED:
            return "401 Unauthorized";
        case HTTP_NOT_FOUND:
            return "404 Not Found";
        case HTTP_TEAPOT:
            return "418 I AM A TEAPOT!";
        case HTTP_INTERNAL_SERVER_ERROR:
            return "500 Internal Server Error";
        default:
            return "Unknown HTTP status code";
    }
}
