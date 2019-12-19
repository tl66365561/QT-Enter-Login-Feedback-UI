
#include "feedback.h"


FeedbackForm::FeedbackForm(QWidget* parent)
						:QMainWindow(parent)
{


	Sleep(2000);
	QDesktopServices::openUrl(QUrl("http://qa.wps.cn:9703/feedback/front?product_name=WPS%e7%99%bb%e5%bd%95%e8%af%8a%e6%96%ad&is_show_editor=true"));	
}


FeedbackForm::~FeedbackForm(){

}