#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

//#include "http-cpp/httplib.h"
#include "httplistener.h"


#include "httprequesthandler.h"

using namespace stefanfrings;

/**
  The request handler receives incoming HTTP requests and generates responses.
*/

class RequestHandler : public HttpRequestHandler {
    Q_OBJECT
    Q_DISABLE_COPY(RequestHandler)
public:

    /**
      Constructor.
      @param parent Parent object
    */
    RequestHandler(QObject* parent=0);

    /**
      Destructor
    */
    ~RequestHandler();

    /**
      Process an incoming HTTP request.
      @param request The received HTTP request
      @param response Must be used to return the response
    */
    void service(HttpRequest& request, HttpResponse& response);

};




class HttpServer : public QObject
{
   Q_OBJECT
public:
    HttpServer();




private:
//    httplib::Server m_httpServer;
    stefanfrings::HttpListener *m_httpServer{nullptr};
};

#endif // HTTP_SERVER_H
