#include "http_server.h"
#include <QDebug>

// 服务端地址 https://github.com/fffaraz/QtWebApp
//https://github.com/fffaraz/QtWebApp


HttpServer::HttpServer()
{
    // HTTP
//    m_httpServer.Get("/hi", [](const httplib::Request &, httplib::Response &res) {
//      res.set_content("Hello World!", "text/plain");
//    });

    QSettings* settings = new QSettings("config.ini", QSettings::IniFormat, this);
    // settings->setValue("host","192.168.0.100");
    settings->setValue("port", 8080);
    settings->setValue("minThreads", 4);
    settings->setValue("maxThreads", 100);
    settings->setValue("cleanupInterval", 60000);
    settings->setValue("readTimeout", 60000);
    settings->setValue("maxRequestSize", 16000);
    settings->setValue("maxMultiPartSize", 10000000);


    qDebug() << settings->value("port");

    quint16 port = settings->value("port").toUInt();

    // Configure and start the TCP listener
    new stefanfrings::HttpListener(settings, new RequestHandler(this), this);


}











RequestHandler::RequestHandler(QObject* parent)
    :HttpRequestHandler(parent)
{
    qDebug("RequestHandler: created");
}


RequestHandler::~RequestHandler()
{
    qDebug("RequestHandler: deleted");
}

void RequestHandler::service(HttpRequest& request, HttpResponse& response)
{
    QByteArray path=request.getPath();
    qDebug("Conroller: path=%s",path.data());

    // Set a response header
    response.setHeader("Content-Type", "text/html; charset=ISO-8859-1");

    // Return a simple HTML document
    response.write("<html><body>Hello World!</body></html>",true);

    qDebug("RequestHandler: finished request");
}

