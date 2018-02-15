#include <iostream>
#include <tinyxml2.h>

using namespace tinyxml2;

int main(int argc, char const *argv[])
{    
	XMLDocument doc;
	doc.LoadFile("data/Player.xml");
	
	XMLElement* root = doc.RootElement();
	for (XMLElement* child = root->FirstChildElement(); child != nullptr; child = child->NextSiblingElement())
	{
		std::cout << child->Name() << ": " << child->GetText() << '\n';
	}

	return EXIT_SUCCESS;
}