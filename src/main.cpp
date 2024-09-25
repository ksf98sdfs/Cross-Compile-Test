#include <QApplication>
#include <QPushButton>
#include <QUrl>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>

int main(int argc, char **argv)
{
  QApplication app (argc, argv);

  QPushButton button ("Hello world !");
  button.show();
  
  QNetworkAccessManager* mgr = new QNetworkAccessManager(&button);
  QUrl url("https://www.svt.se/text-tv/100");
  QNetworkReply* reply = mgr->get(QNetworkRequest(url));
  QObject::connect(mgr, &QNetworkAccessManager::finished, [reply]() {
    if (reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt() == 200) {
      return 0;
    } else {
      return 1;
    }
  });

  return app.exec();
}
