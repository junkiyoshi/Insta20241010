#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(25);
	ofSetWindowTitle("openframeworks");

	ofBackground(39);
	ofSetLineWidth(5);
	ofNoFill();
	ofEnableDepthTest();
	ofEnableBlendMode(ofBlendMode::OF_BLENDMODE_ADD);
}

//--------------------------------------------------------------
void ofApp::update() {

	ofSeedRandom(39);
}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();

	ofColor color;
	for (int i = 0; i < 5000; i++) {
		
		color.setHsb(ofMap(i, 0, 5000, 0, 255), ofRandom(100, 255), ofRandom(100, 255));
		auto noise_seed = glm::vec3(ofRandom(1000), ofRandom(1000), ofRandom(1000));

		for (int k = 0; k < 30; k++) {

			auto location = glm::vec3(
				ofMap(ofNoise(noise_seed.x, (ofGetFrameNum() + k) * 0.05), 0, 1, -1000, 1000),
				ofMap(ofNoise(noise_seed.y, (ofGetFrameNum() + k) * 0.0005), 0, 1, -1000, 1000),
				ofMap(ofNoise(noise_seed.z, (ofGetFrameNum() + k) * 0.05), 0, 1, -1000, 1000));
			auto next = glm::vec3(
				ofMap(ofNoise(noise_seed.x, (ofGetFrameNum() + k + 1) * 0.05), 0, 1, -1000, 1000),
				ofMap(ofNoise(noise_seed.y, (ofGetFrameNum() + k + 1) * 0.0005), 0, 1, -1000, 1000),
				ofMap(ofNoise(noise_seed.z, (ofGetFrameNum() + k + 1) * 0.05), 0, 1, -1000, 1000));

			if (location.x > 800) { location.x = 800; }
			if (location.x < -800) { location.x = -800; }
			if (next.x > 800) { next.x = 800; }
			if (next.x < -800) { next.x = -800; }

			if (location.y > 800) { location.y = 800; }
			if (location.y < -800) { location.y = -800; }
			if (next.y > 800) { next.y = 800; }
			if (next.y < -800) { next.y = -800; }

			if (location.z > 800) { location.z = 800; }
			if (location.z < -800) { location.z = -800; }
			if (next.z > 800) { next.z = 800; }
			if (next.z < -800) { next.z = -800; }

			if (location.y > 0 && location.y < 750) { location.y = 750; }
			if (location.y < 0 && location.y > -750) { location.y = -750; }
			if (next.y > 0 && next.y < 750) { next.y = 750; }
			if (next.y < 0 && next.y > -750) { next.y = -750; }

			auto alpha = ofMap(k, 0, 30, 0, 255);
			ofSetColor(color, alpha);
			ofDrawLine(location, next);
		}

		
	}

	this->cam.end();

	/*
	int start = 250;
	if (ofGetFrameNum() > start) {

		ostringstream os;
		os << setw(4) << setfill('0') << ofGetFrameNum() - start;
		ofImage image;
		image.grabScreen(0, 0, ofGetWidth(), ofGetHeight());
		image.saveImage("image/cap/img_" + os.str() + ".jpg");
		if (ofGetFrameNum() - start >= 25 * 20) {

			std::exit(1);
		}
	}
	*/
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}