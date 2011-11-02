#include "../ticpp/ticpp.h"
using namespace ticpp;

#include <iostream>
using namespace std;

int main() {
	try {
		ticpp::Document doc("generatedXml.xml");

		Declaration declaration("1.0", "", "");
		doc.InsertEndChild(declaration);

		Element rootElem;
		rootElem.SetValue("rootElem");
		rootElem.SetAttribute("rootAttr", "rootAttrValue");
		Element childElem1;
		childElem1.SetValue("childElem");
		childElem1.SetText("This is the child elem 1");
		rootElem.InsertEndChild(childElem1);

		Element childElem2;
		childElem2.SetValue("childElem");
		childElem2.SetText("This is the child elem 2");
		rootElem.InsertEndChild(childElem2);

		doc.InsertEndChild(rootElem);
		doc.SaveFile();
	} catch (ticpp::Exception& ex) {
		cerr << ex.what() << endl;
	}
	return 0;
}
