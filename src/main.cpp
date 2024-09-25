#include <QApplication>
#include <QMainWindow>
#include <QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

int main(int argc, char **argv)
{
  QApplication* app = new QApplication(argc, argv);

  QMainWindow* mainWindow = new QMainWindow(nullptr);
  mainWindow->show();
  
  QNetworkAccessManager* mgr = new QNetworkAccessManager(mainWindow);
  QUrl url("https://www.svt.se/text-tv/100");
  QNetworkReply* reply = mgr->get(QNetworkRequest(url));
  QObject::connect(mgr, &QNetworkAccessManager::finished, [reply]() {
    if (reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() == 200) {
      return 0;
    } else {
      return 1;
    }
  });

  QObject::connect(app, &QApplication::aboutToQuit, mainWindow, &QMainWindow::deleteLater);
  
  return app->exec();
}
