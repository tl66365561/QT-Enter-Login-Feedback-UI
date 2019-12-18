
#include "feedback.h"


FeedbackForm::FeedbackForm(QWidget* parent)
						:QMainWindow(parent)
{


	Sleep(2000);
	QDesktopServices::openUrl(QUrl("https://blog.csdn.net/tonglin12138/article/details/103469285"));	
}


FeedbackForm::~FeedbackForm(){

}