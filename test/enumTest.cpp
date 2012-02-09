#include <iostream>
#include "../include/Functions.h"
#include <string>

/**
 * This class is a wrapper to a enumeration of video codecs supported by the component.
 */
class VideoCodec {
public:
	/**
	 * Enumeration with the video codecs supported.
	 * 	- H264 The h264 (MPEG4 Advanced Video Coding) video codec.
	 *  - MPEG2 The mpeg2 video codec.
	 *  - WEBM The Web-M Video Codec used in HTML5 compatible browsers
	 *  - MPEG1 The mpeg1 video codec.
	 *  - COPY A special that can be used to force the output video just copy the source video.
	 */
	enum Type {H264=1, MPEG2, MPEG1, WEBM, COPY, NONE,};

	static VideoCodec strToVideoCodec(std::string str);

	std::string toString() const;

	VideoCodec(VideoCodec::Type type);

	VideoCodec(const VideoCodec& videoCodec);

	VideoCodec& operator=(const VideoCodec &videoCodec);

	VideoCodec& operator=(const VideoCodec::Type type);

	bool operator==(const VideoCodec &videoCodec) const;

	bool operator==(const VideoCodec::Type type) const;

	bool operator!=(const VideoCodec &videoCodec) const;

	bool operator!=(const VideoCodec::Type type) const;

	void setType(VideoCodec::Type type);

	VideoCodec::Type getType() const;

	friend std::ostream &operator<<(std::ostream &out,
			const VideoCodec& videoCodec);

private:
	std::string typeToStr(VideoCodec::Type type);
	VideoCodec::Type type;
	static char* stringItems[];
	char* stringItem;
};

char* VideoCodec::stringItems[] = {
		(char*) "H264",
		(char*) "MPEG2",
		(char*) "MPEG1",
		(char*) "WEBM",
		(char*) "COPY",
		(char*) "NONE", };

std::string VideoCodec::toString() const {
	return stringItem;
}

VideoCodec::VideoCodec(VideoCodec::Type type) {
	setType(type);
}

VideoCodec::VideoCodec(const VideoCodec& videoCodec) {
	setType(videoCodec.type);
}

VideoCodec& VideoCodec::operator=(const VideoCodec &videoCodec) {
	setType(videoCodec.type);
	return *this;
}

VideoCodec& VideoCodec::operator=(const VideoCodec::Type type) {
	setType(type);
	return *this;
}

bool VideoCodec::operator==(const VideoCodec &videoCodec) const {
	return (this->type == videoCodec.type);
}

bool VideoCodec::operator==(const VideoCodec::Type type) const {
	return (this->type == type);
}

bool VideoCodec::operator!=(const VideoCodec &videoCodec) const {
	return (this->type != videoCodec.type);
}

bool VideoCodec::operator!=(const VideoCodec::Type type) const {
	return (this->type != type);
}

void VideoCodec::setType(VideoCodec::Type type) {
	this->type = type;
	switch(this->type) {
	case VideoCodec::H264:
		this->stringItem = stringItems[0];
		break;
	case VideoCodec::MPEG2:
		this->stringItem = stringItems[1];
		break;
	case VideoCodec::MPEG1:
		this->stringItem = stringItems[2];
		break;
	case VideoCodec::WEBM:
		this->stringItem = stringItems[3];
		break;
	case VideoCodec::COPY:
		this->stringItem = stringItems[4];
		break;
	case VideoCodec::NONE:
		this->stringItem = stringItems[5];
		break;
	default:
		//TODO: Throw exception
		break;
	}
}

VideoCodec::Type VideoCodec::getType() const {
	return type;
}

VideoCodec VideoCodec::strToVideoCodec(std::string str) {
	VideoCodec::Type type;
	std::string aux = cpputil::Functions::toUpperCase(str);
	if (aux == "H264") {
		type = VideoCodec::H264;
	} else if (aux == "MPEG2") {
		type = VideoCodec::MPEG2;
	} else if (aux == "MPEG1") {
		type = VideoCodec::MPEG1;
	} else if (aux == "WEBM") {
		type = VideoCodec::WEBM;
	} else if (aux == "COPY") {
		type = VideoCodec::COPY;
	} else if (aux == "NONE") {
		type = VideoCodec::NONE;
	} else {
		//TODO: Throw exception
	}
	return VideoCodec(type);
}

std::ostream& operator<<(std::ostream &out,
		const VideoCodec& videoCodec) {

	out<< videoCodec.toString();
	return out;
}

int main() {
	VideoCodec vCodec1(VideoCodec::H264);
	VideoCodec vCodec2(vCodec1);
	VideoCodec vCodec3 = VideoCodec::MPEG2;
	VideoCodec vCodec4 = vCodec3;

	std::cout << "vCodec1: " << vCodec1 << std::endl;
	std::cout << "vCodec2: " << vCodec2 << std::endl;
	std::cout << "vCodec3: " << vCodec3 << std::endl;
	std::cout << "vCodec4: " << vCodec4 << std::endl;

	std::cout << "vCodec1 == vCodec2: " << (vCodec1 == vCodec2) << std::endl;
	std::cout << "vCodec3 == vCodec4: " << (vCodec3 == vCodec4) << std::endl;
	std::cout << "vCodec1 == vCodec3: " << (vCodec1 == vCodec3) << std::endl;
	std::cout << "vCodec2 == vCodec4: " << (vCodec2 == vCodec4) << std::endl;

	std::cout << "vCodec1 != vCodec2: " << (vCodec1 != vCodec2) << std::endl;
	std::cout << "vCodec3 != vCodec4: " << (vCodec3 != vCodec4) << std::endl;
	std::cout << "vCodec1 != vCodec3: " << (vCodec1 != vCodec3) << std::endl;
	std::cout << "vCodec2 != vCodec4: " << (vCodec2 != vCodec4) << std::endl;

	return 0;
}
