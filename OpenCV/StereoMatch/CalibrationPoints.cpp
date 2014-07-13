#include "CalibrationPoints.h"

using namespace std;

std::vector<cv::Point3f> InitUpperPlaneWorld()
{
	int i = 0;
	//Alle z Koordinaten auf 380 setzen
	vector<cv::Point3f> upperPlaneWorld(48, cv::Point3f(0.0, 0.0, 380.0));

	upperPlaneWorld[i++].x = 200.500000;
	upperPlaneWorld[i++].x = 266.500000;
	upperPlaneWorld[i++].x = 330.500000;
	upperPlaneWorld[i++].x = 395.500000;
	upperPlaneWorld[i++].x = 460.500000;
	upperPlaneWorld[i++].x = 526.500000;
	upperPlaneWorld[i++].x = 590.500000;
	upperPlaneWorld[i++].x = 655.500000;
	upperPlaneWorld[i++].x = 200.500000;
	upperPlaneWorld[i++].x = 266.500000;
	upperPlaneWorld[i++].x = 330.500000;
	upperPlaneWorld[i++].x = 395.500000;
	upperPlaneWorld[i++].x = 460.500000;
	upperPlaneWorld[i++].x = 526.500000;
	upperPlaneWorld[i++].x = 590.500000;
	upperPlaneWorld[i++].x = 655.500000;
	upperPlaneWorld[i++].x = 200.500000;
	upperPlaneWorld[i++].x = 266.500000;
	upperPlaneWorld[i++].x = 330.500000;
	upperPlaneWorld[i++].x = 395.500000;
	upperPlaneWorld[i++].x = 460.500000;
	upperPlaneWorld[i++].x = 526.500000;
	upperPlaneWorld[i++].x = 590.500000;
	upperPlaneWorld[i++].x = 655.500000;
	upperPlaneWorld[i++].x = 200.500000;
	upperPlaneWorld[i++].x = 266.500000;
	upperPlaneWorld[i++].x = 330.500000;
	upperPlaneWorld[i++].x = 395.500000;
	upperPlaneWorld[i++].x = 460.500000;
	upperPlaneWorld[i++].x = 526.500000;
	upperPlaneWorld[i++].x = 590.500000;
	upperPlaneWorld[i++].x = 655.500000;
	upperPlaneWorld[i++].x = 200.500000;
	upperPlaneWorld[i++].x = 266.500000;
	upperPlaneWorld[i++].x = 330.500000;
	upperPlaneWorld[i++].x = 395.500000;
	upperPlaneWorld[i++].x = 460.500000;
	upperPlaneWorld[i++].x = 526.500000;
	upperPlaneWorld[i++].x = 590.500000;
	upperPlaneWorld[i++].x = 655.500000;
	upperPlaneWorld[i++].x = 200.500000;
	upperPlaneWorld[i++].x = 266.500000;
	upperPlaneWorld[i++].x = 330.500000;
	upperPlaneWorld[i++].x = 395.500000;
	upperPlaneWorld[i++].x = 460.500000;
	upperPlaneWorld[i++].x = 526.500000;
	upperPlaneWorld[i++].x = 590.500000;
	upperPlaneWorld[i++].x = 655.500000;

	i = 0;
	upperPlaneWorld[i++].y =  41.000000;
	upperPlaneWorld[i++].y =  41.000000;
	upperPlaneWorld[i++].y =  41.000000;
	upperPlaneWorld[i++].y =  41.000000;
	upperPlaneWorld[i++].y =  41.000000;
	upperPlaneWorld[i++].y =  41.000000;
	upperPlaneWorld[i++].y =  41.000000;
	upperPlaneWorld[i++].y =  41.000000;
	upperPlaneWorld[i++].y =  111.000000;
	upperPlaneWorld[i++].y =  111.000000;
	upperPlaneWorld[i++].y =  111.000000;
	upperPlaneWorld[i++].y =  111.000000;
	upperPlaneWorld[i++].y =  111.000000;
	upperPlaneWorld[i++].y =  111.000000;
	upperPlaneWorld[i++].y =  111.000000;
	upperPlaneWorld[i++].y =  111.000000;
	upperPlaneWorld[i++].y =  181.000000;
	upperPlaneWorld[i++].y =  181.000000;
	upperPlaneWorld[i++].y =  181.000000;
	upperPlaneWorld[i++].y =  181.000000;
	upperPlaneWorld[i++].y =  181.000000;
	upperPlaneWorld[i++].y =  181.000000;
	upperPlaneWorld[i++].y =  181.000000;
	upperPlaneWorld[i++].y =  181.000000;
	upperPlaneWorld[i++].y =  251.000000;
	upperPlaneWorld[i++].y =  251.000000;
	upperPlaneWorld[i++].y =  251.000000;
	upperPlaneWorld[i++].y =  251.000000;
	upperPlaneWorld[i++].y =  251.000000;
	upperPlaneWorld[i++].y =  251.000000;
	upperPlaneWorld[i++].y =  251.000000;
	upperPlaneWorld[i++].y =  251.000000;
	upperPlaneWorld[i++].y =  321.000000;
	upperPlaneWorld[i++].y =  321.000000;
	upperPlaneWorld[i++].y =  321.000000;
	upperPlaneWorld[i++].y =  321.000000;
	upperPlaneWorld[i++].y =  321.000000;
	upperPlaneWorld[i++].y =  321.000000;
	upperPlaneWorld[i++].y =  321.000000;
	upperPlaneWorld[i++].y =  321.000000;
	upperPlaneWorld[i++].y =  391.000000;
	upperPlaneWorld[i++].y =  391.000000;
	upperPlaneWorld[i++].y =  391.000000;
	upperPlaneWorld[i++].y =  391.000000;
	upperPlaneWorld[i++].y =  391.000000;
	upperPlaneWorld[i++].y =  391.000000;
	upperPlaneWorld[i++].y =  391.000000;
	upperPlaneWorld[i++].y =  391.000000;

	return upperPlaneWorld;
}

vector<cv::Point3f> InitLowerPlaneWorld()
{
	int i = 0;
	//Alle z Koordinaten auf 10.0 setzen
	vector<cv::Point3f> lowerPlaneWorld(24, cv::Point3f(0.0, 0.0, 10.0));

	lowerPlaneWorld[i++].x = 220.500000;
	lowerPlaneWorld[i++].x = 303.500000;
  lowerPlaneWorld[i++].x = 386.500000;
  lowerPlaneWorld[i++].x = 469.500000;
  lowerPlaneWorld[i++].x = 552.500000;
  lowerPlaneWorld[i++].x = 635.500000;
  lowerPlaneWorld[i++].x = 220.500000;
  lowerPlaneWorld[i++].x = 303.500000;
  lowerPlaneWorld[i++].x = 386.500000;
  lowerPlaneWorld[i++].x = 469.500000;
  lowerPlaneWorld[i++].x = 552.500000;
  lowerPlaneWorld[i++].x = 635.500000;
  lowerPlaneWorld[i++].x = 220.500000;
  lowerPlaneWorld[i++].x = 303.500000;
  lowerPlaneWorld[i++].x = 386.500000;
  lowerPlaneWorld[i++].x = 469.500000;
  lowerPlaneWorld[i++].x = 552.500000;
  lowerPlaneWorld[i++].x = 635.500000;
  lowerPlaneWorld[i++].x = 220.500000;
  lowerPlaneWorld[i++].x = 303.500000;
  lowerPlaneWorld[i++].x = 386.500000;
	lowerPlaneWorld[i++].x = 469.500000;
	lowerPlaneWorld[i++].x = 552.500000;
	lowerPlaneWorld[i++].x = 635.500000;

	i = 0;
	lowerPlaneWorld[i++].y =  41.00;
	lowerPlaneWorld[i++].y =  41.00;
	lowerPlaneWorld[i++].y =  41.00;
	lowerPlaneWorld[i++].y =  41.00;
	lowerPlaneWorld[i++].y =  41.00;
	lowerPlaneWorld[i++].y =  41.00;
	lowerPlaneWorld[i++].y = 151.00;
	lowerPlaneWorld[i++].y = 151.00;
	lowerPlaneWorld[i++].y = 151.00;
	lowerPlaneWorld[i++].y = 151.00;
	lowerPlaneWorld[i++].y = 151.00;
	lowerPlaneWorld[i++].y = 151.00;
	lowerPlaneWorld[i++].y =  261.00;
	lowerPlaneWorld[i++].y =  261.00;
	lowerPlaneWorld[i++].y =  261.00;
	lowerPlaneWorld[i++].y =  261.00;
	lowerPlaneWorld[i++].y =  261.00;
	lowerPlaneWorld[i++].y =  261.00;
	lowerPlaneWorld[i++].y =  371.00;
	lowerPlaneWorld[i++].y =  371.00;
	lowerPlaneWorld[i++].y =  371.00;
	lowerPlaneWorld[i++].y =  371.00;
	lowerPlaneWorld[i++].y =  371.00;
	lowerPlaneWorld[i++].y =  371.00;

	return lowerPlaneWorld;
}

std::vector< std::vector<cv::Point3f> > InitWorld()
{
	std::vector< std::vector<cv::Point3f> > refWorld;

	refWorld.push_back( InitUpperPlaneWorld() );
	refWorld.push_back( InitLowerPlaneWorld() );

//	for(unsigned i=0; i<refWorld.size(); i++)
//	{
//		for(unsigned j=0; j<refWorld[i].size(); j++)
//		{
//			cout << "Ebene " << i << " " << j << refWorld[i][j] << endl;
//		}
//	}

	return refWorld;
}

vector<cv::Point2f> InitImageCoordUpperPlaneCam1()
{
	vector<cv::Point2f> imagePointsUpperPlane(48);
	int i = 0;

	imagePointsUpperPlane[i++].x = 121.565361;
  imagePointsUpperPlane[i++].x = 196.811340;
  imagePointsUpperPlane[i++].x = 281.423553;
  imagePointsUpperPlane[i++].x = 371.770203;
  imagePointsUpperPlane[i++].x = 463.456543;
  imagePointsUpperPlane[i++].x = 551.698425;
  imagePointsUpperPlane[i++].x = 632.997314;
  imagePointsUpperPlane[i++].x = 704.445435;
  imagePointsUpperPlane[i++].x = 111.152061;
  imagePointsUpperPlane[i++].x = 188.588837;
  imagePointsUpperPlane[i++].x = 276.387451;
  imagePointsUpperPlane[i++].x = 370.000000;
  imagePointsUpperPlane[i++].x = 465.269440;
  imagePointsUpperPlane[i++].x = 556.700623;
  imagePointsUpperPlane[i++].x = 640.502625;
  imagePointsUpperPlane[i++].x = 714.000000;
  imagePointsUpperPlane[i++].x = 106.190773;
  imagePointsUpperPlane[i++].x = 184.995026;
  imagePointsUpperPlane[i++].x = 273.980682;
  imagePointsUpperPlane[i++].x = 369.571320;
  imagePointsUpperPlane[i++].x = 466.500000;
  imagePointsUpperPlane[i++].x = 559.505371;
  imagePointsUpperPlane[i++].x = 644.766846;
  imagePointsUpperPlane[i++].x = 718.752319;
  imagePointsUpperPlane[i++].x = 107.815315;
  imagePointsUpperPlane[i++].x = 186.040756;
  imagePointsUpperPlane[i++].x = 275.123932;
  imagePointsUpperPlane[i++].x = 370.289368;
  imagePointsUpperPlane[i++].x = 466.999115;
  imagePointsUpperPlane[i++].x = 559.723267;
  imagePointsUpperPlane[i++].x = 644.752747;
  imagePointsUpperPlane[i++].x = 718.756042;
  imagePointsUpperPlane[i++].x = 115.164558;
  imagePointsUpperPlane[i++].x = 192.387039;
  imagePointsUpperPlane[i++].x = 279.264679;
  imagePointsUpperPlane[i++].x = 372.403412;
  imagePointsUpperPlane[i++].x = 466.660583;
  imagePointsUpperPlane[i++].x = 557.360718;
  imagePointsUpperPlane[i++].x = 640.611816;
  imagePointsUpperPlane[i++].x = 714.000000;
  imagePointsUpperPlane[i++].x = 127.858727;
  imagePointsUpperPlane[i++].x = 203.000000;
  imagePointsUpperPlane[i++].x = 286.114410;
  imagePointsUpperPlane[i++].x = 376.000000;
  imagePointsUpperPlane[i++].x = 465.829681;
  imagePointsUpperPlane[i++].x = 553.165833;
  imagePointsUpperPlane[i++].x = 633.321533;
  imagePointsUpperPlane[i++].x = 704.540161;

  i = 0;
  imagePointsUpperPlane[i++].y = 82.507515;
  imagePointsUpperPlane[i++].y = 72.735168;
  imagePointsUpperPlane[i++].y = 65.929077;
  imagePointsUpperPlane[i++].y = 62.820820;
  imagePointsUpperPlane[i++].y = 63.931019;
  imagePointsUpperPlane[i++].y = 68.773041;
  imagePointsUpperPlane[i++].y = 76.949135;
  imagePointsUpperPlane[i++].y = 87.096107;
  imagePointsUpperPlane[i++].y = 170.716904;
  imagePointsUpperPlane[i++].y = 164.107971;
  imagePointsUpperPlane[i++].y = 159.610550;
  imagePointsUpperPlane[i++].y = 157.500000;
  imagePointsUpperPlane[i++].y = 157.844910;
  imagePointsUpperPlane[i++].y = 160.712128;
  imagePointsUpperPlane[i++].y = 165.608978;
  imagePointsUpperPlane[i++].y = 173.000000;
  imagePointsUpperPlane[i++].y = 265.216187;
  imagePointsUpperPlane[i++].y = 262.977051;
  imagePointsUpperPlane[i++].y = 261.282959;
  imagePointsUpperPlane[i++].y = 260.045624;
  imagePointsUpperPlane[i++].y = 260.000000;
	imagePointsUpperPlane[i++].y = 260.444427;
	imagePointsUpperPlane[i++].y = 261.388397;
	imagePointsUpperPlane[i++].y = 263.289185;
	imagePointsUpperPlane[i++].y = 362.062347;
	imagePointsUpperPlane[i++].y = 364.165924;
	imagePointsUpperPlane[i++].y = 365.354584;
	imagePointsUpperPlane[i++].y = 365.211914;
	imagePointsUpperPlane[i++].y = 364.360657;
	imagePointsUpperPlane[i++].y = 362.242554;
	imagePointsUpperPlane[i++].y = 359.325623;
	imagePointsUpperPlane[i++].y = 355.530426;
	imagePointsUpperPlane[i++].y = 455.022034;
	imagePointsUpperPlane[i++].y = 461.229309;
	imagePointsUpperPlane[i++].y = 465.115723;
	imagePointsUpperPlane[i++].y = 465.976227;
	imagePointsUpperPlane[i++].y = 464.085388;
	imagePointsUpperPlane[i++].y = 459.846649;
	imagePointsUpperPlane[i++].y = 453.129791;
	imagePointsUpperPlane[i++].y = 446.000000;
	imagePointsUpperPlane[i++].y = 539.806580;
	imagePointsUpperPlane[i++].y = 550.000000;
	imagePointsUpperPlane[i++].y = 555.029602;
	imagePointsUpperPlane[i++].y = 558.000000;
	imagePointsUpperPlane[i++].y = 554.440186;
	imagePointsUpperPlane[i++].y = 548.399902;
	imagePointsUpperPlane[i++].y = 539.029541;
	imagePointsUpperPlane[i++].y = 527.277100;

	return imagePointsUpperPlane;
}

std::vector<cv::Point2f> InitImageCoordLowerPlaneCam1()
{
	vector<cv::Point2f> imagePointsLowerPlane(24);
  int i = 0;
  imagePointsLowerPlane[i++].x = 226.140305;
  imagePointsLowerPlane[i++].x = 292.527283;
  imagePointsLowerPlane[i++].x = 361.893158;
  imagePointsLowerPlane[i++].x = 432.202698;
  imagePointsLowerPlane[i++].x = 501.657043;
  imagePointsLowerPlane[i++].x = 567.875427;
  imagePointsLowerPlane[i++].x = 223.045029;
  imagePointsLowerPlane[i++].x = 290.669281;
  imagePointsLowerPlane[i++].x = 361.078888;
  imagePointsLowerPlane[i++].x = 432.730713;
  imagePointsLowerPlane[i++].x = 503.364960;
  imagePointsLowerPlane[i++].x = 571.000000;
  imagePointsLowerPlane[i++].x = 223.537216;
  imagePointsLowerPlane[i++].x = 291.127106;
  imagePointsLowerPlane[i++].x = 361.660431;
  imagePointsLowerPlane[i++].x = 433.500000;
  imagePointsLowerPlane[i++].x = 504.066528;
  imagePointsLowerPlane[i++].x = 571.678467;
  imagePointsLowerPlane[i++].x = 227.675308;
  imagePointsLowerPlane[i++].x = 294.207733;
  imagePointsLowerPlane[i++].x = 363.658112;
  imagePointsLowerPlane[i++].x = 434.278229;
  imagePointsLowerPlane[i++].x = 503.731018;
  imagePointsLowerPlane[i++].x = 569.842957;

  i = 0;
  imagePointsLowerPlane[i++].y = 159.780853;
  imagePointsLowerPlane[i++].y = 156.744476;
  imagePointsLowerPlane[i++].y = 155.133942;
  imagePointsLowerPlane[i++].y = 155.067627;
  imagePointsLowerPlane[i++].y = 156.120255;
  imagePointsLowerPlane[i++].y = 158.875412;
  imagePointsLowerPlane[i++].y = 250.432159;
  imagePointsLowerPlane[i++].y = 248.711365;
  imagePointsLowerPlane[i++].y = 247.997360;
  imagePointsLowerPlane[i++].y = 247.634933;
  imagePointsLowerPlane[i++].y = 247.728394;
  imagePointsLowerPlane[i++].y = 248.500000;
  imagePointsLowerPlane[i++].y = 343.529419;
  imagePointsLowerPlane[i++].y = 343.675507;
  imagePointsLowerPlane[i++].y = 343.500000;
  imagePointsLowerPlane[i++].y = 342.660431;
  imagePointsLowerPlane[i++].y = 342.015564;
  imagePointsLowerPlane[i++].y = 340.674316;
  imagePointsLowerPlane[i++].y = 434.444397;
  imagePointsLowerPlane[i++].y = 436.066467;
  imagePointsLowerPlane[i++].y = 436.651306;
  imagePointsLowerPlane[i++].y = 435.714172;
  imagePointsLowerPlane[i++].y = 433.782867;
  imagePointsLowerPlane[i++].y = 430.244568;

  return imagePointsLowerPlane;
}


std::vector< std::vector<cv::Point2f> > InitImageCoordCam1()
{
	std::vector< std::vector<cv::Point2f> > imageCoordPoints;

	imageCoordPoints.push_back(InitImageCoordUpperPlaneCam1() );
	imageCoordPoints.push_back(InitImageCoordLowerPlaneCam1() );

	return imageCoordPoints;
}

vector<cv::Point2f> InitImageCoordUpperPlaneCam2()
{
	vector<cv::Point2f> imagePointsUpperPlane(48);
	int i = 0;
	imagePointsUpperPlane[i++].x =  121.154137;
	imagePointsUpperPlane[i++].x =  189.536774;
	imagePointsUpperPlane[i++].x =  268.290375;
	imagePointsUpperPlane[i++].x =  354.945984;
	imagePointsUpperPlane[i++].x =  446.000000;
	imagePointsUpperPlane[i++].x =  536.878357;
	imagePointsUpperPlane[i++].x =  623.472778;
	imagePointsUpperPlane[i++].x =  701.000000;
	imagePointsUpperPlane[i++].x =  111.500000;
	imagePointsUpperPlane[i++].x =  182.005692;
	imagePointsUpperPlane[i++].x =  263.204071;
	imagePointsUpperPlane[i++].x =  352.799683;
	imagePointsUpperPlane[i++].x =  447.387177;
	imagePointsUpperPlane[i++].x =  541.700134;
	imagePointsUpperPlane[i++].x =  631.397583;
	imagePointsUpperPlane[i++].x =  711.634094;
	imagePointsUpperPlane[i++].x =  107.400482;
	imagePointsUpperPlane[i++].x =  178.500000;
	imagePointsUpperPlane[i++].x =  260.866760;
	imagePointsUpperPlane[i++].x =  352.111053;
	imagePointsUpperPlane[i++].x =  448.409973;
	imagePointsUpperPlane[i++].x =  544.622070;
	imagePointsUpperPlane[i++].x =  635.552551;
	imagePointsUpperPlane[i++].x =  717.107849;
	imagePointsUpperPlane[i++].x =  108.558006;
	imagePointsUpperPlane[i++].x =  179.665558;
	imagePointsUpperPlane[i++].x =  261.940674;
	imagePointsUpperPlane[i++].x =  353.032318;
	imagePointsUpperPlane[i++].x =  449.017426;
	imagePointsUpperPlane[i++].x =  545.007812;
	imagePointsUpperPlane[i++].x =  635.675781;
	imagePointsUpperPlane[i++].x =  716.869263;
	imagePointsUpperPlane[i++].x =  115.376228;
	imagePointsUpperPlane[i++].x =  185.336746;
	imagePointsUpperPlane[i++].x =  266.323120;
	imagePointsUpperPlane[i++].x =  355.303711;
	imagePointsUpperPlane[i++].x =  449.182587;
	imagePointsUpperPlane[i++].x =  542.922668;
	imagePointsUpperPlane[i++].x =  631.639282;
	imagePointsUpperPlane[i++].x =  711.498230;
	imagePointsUpperPlane[i++].x =  127.000000;
	imagePointsUpperPlane[i++].x =  195.000000;
	imagePointsUpperPlane[i++].x =  273.128113;
	imagePointsUpperPlane[i++].x =  358.775513;
	imagePointsUpperPlane[i++].x =  448.843323;
	imagePointsUpperPlane[i++].x =  538.704346;
	imagePointsUpperPlane[i++].x =  624.012817;
	imagePointsUpperPlane[i++].x =  701.215515;

	i = 0;
	imagePointsUpperPlane[i++].y =99.234489;
	imagePointsUpperPlane[i++].y =87.584595;
	imagePointsUpperPlane[i++].y =78.129753;
	imagePointsUpperPlane[i++].y =71.667099;
	imagePointsUpperPlane[i++].y =69.000000;
	imagePointsUpperPlane[i++].y =70.183174;
	imagePointsUpperPlane[i++].y =75.426605;
	imagePointsUpperPlane[i++].y =84.000000;
	imagePointsUpperPlane[i++].y =183.000000;
	imagePointsUpperPlane[i++].y =175.527679;
	imagePointsUpperPlane[i++].y =169.379471;
	imagePointsUpperPlane[i++].y =165.183563;
	imagePointsUpperPlane[i++].y =163.111313;
	imagePointsUpperPlane[i++].y =163.700119;
	imagePointsUpperPlane[i++].y =166.963898;
	imagePointsUpperPlane[i++].y =172.239594;
	imagePointsUpperPlane[i++].y =272.606049;
	imagePointsUpperPlane[i++].y =270.000000;
	imagePointsUpperPlane[i++].y =268.052368;
	imagePointsUpperPlane[i++].y =266.561584;
	imagePointsUpperPlane[i++].y =265.705505;
	imagePointsUpperPlane[i++].y =265.759674;
	imagePointsUpperPlane[i++].y =266.424011;
	imagePointsUpperPlane[i++].y =267.627106;
	imagePointsUpperPlane[i++].y =363.951355;
	imagePointsUpperPlane[i++].y =366.804291;
	imagePointsUpperPlane[i++].y =368.999420;
	imagePointsUpperPlane[i++].y =370.391388;
	imagePointsUpperPlane[i++].y =370.565826;
	imagePointsUpperPlane[i++].y =369.788208;
	imagePointsUpperPlane[i++].y =368.032623;
	imagePointsUpperPlane[i++].y =364.960480;
	imagePointsUpperPlane[i++].y =452.257477;
	imagePointsUpperPlane[i++].y =459.714600;
	imagePointsUpperPlane[i++].y =465.752258;
	imagePointsUpperPlane[i++].y =469.758728;
	imagePointsUpperPlane[i++].y =470.993622;
	imagePointsUpperPlane[i++].y =469.412109;
	imagePointsUpperPlane[i++].y =465.153351;
	imagePointsUpperPlane[i++].y =458.500916;
	imagePointsUpperPlane[i++].y =534.000000;
	imagePointsUpperPlane[i++].y =545.000000;
	imagePointsUpperPlane[i++].y =553.707336;
	imagePointsUpperPlane[i++].y =559.655212;
	imagePointsUpperPlane[i++].y =561.565979;
	imagePointsUpperPlane[i++].y =559.588989;
	imagePointsUpperPlane[i++].y =553.354004;
	imagePointsUpperPlane[i++].y =543.354309;

	return imagePointsUpperPlane;
}

std::vector<cv::Point2f> InitImageCoordLowerPlaneCam2()
{
	vector<cv::Point2f> imagePointsLowerPlane(24);
	int i = 0;
	imagePointsLowerPlane[i++].x =  255.609238;
	imagePointsLowerPlane[i++].x =  320.446167;
	imagePointsLowerPlane[i++].x =  388.938721;
	imagePointsLowerPlane[i++].x =  459.061066;
	imagePointsLowerPlane[i++].x =  528.937073;
	imagePointsLowerPlane[i++].x =  596.139099;
	imagePointsLowerPlane[i++].x =  253.000000;
	imagePointsLowerPlane[i++].x =  319.238159;
	imagePointsLowerPlane[i++].x =  388.725433;
	imagePointsLowerPlane[i++].x =  460.226257;
	imagePointsLowerPlane[i++].x =  531.359924;
	imagePointsLowerPlane[i++].x =  600.000000;
	imagePointsLowerPlane[i++].x =  253.868225;
	imagePointsLowerPlane[i++].x =  319.777496;
	imagePointsLowerPlane[i++].x =  389.555084;
	imagePointsLowerPlane[i++].x =  461.373688;
	imagePointsLowerPlane[i++].x =  532.191040;
	imagePointsLowerPlane[i++].x =  600.838989;
	imagePointsLowerPlane[i++].x =  257.019653;
	imagePointsLowerPlane[i++].x =  322.285736;
	imagePointsLowerPlane[i++].x =  391.253693;
	imagePointsLowerPlane[i++].x =  461.506409;
	imagePointsLowerPlane[i++].x =  531.305237;
	imagePointsLowerPlane[i++].x =  599.026428;

	i = 0;
	imagePointsLowerPlane[i++].y =167.194168;
	imagePointsLowerPlane[i++].y =163.570541;
	imagePointsLowerPlane[i++].y =161.386978;
	imagePointsLowerPlane[i++].y =160.408920;
	imagePointsLowerPlane[i++].y =160.692886;
	imagePointsLowerPlane[i++].y =162.252045;
	imagePointsLowerPlane[i++].y =256.392578;
	imagePointsLowerPlane[i++].y =254.701431;
	imagePointsLowerPlane[i++].y =253.642273;
	imagePointsLowerPlane[i++].y =253.000000;
	imagePointsLowerPlane[i++].y =252.842178;
	imagePointsLowerPlane[i++].y =253.500000;
	imagePointsLowerPlane[i++].y =347.536316;
	imagePointsLowerPlane[i++].y =348.243042;
	imagePointsLowerPlane[i++].y =348.514313;
	imagePointsLowerPlane[i++].y =348.483307;
	imagePointsLowerPlane[i++].y =347.956543;
	imagePointsLowerPlane[i++].y =346.859375;
	imagePointsLowerPlane[i++].y =436.759705;
	imagePointsLowerPlane[i++].y =439.320282;
	imagePointsLowerPlane[i++].y =440.746307;
	imagePointsLowerPlane[i++].y =441.060364;
	imagePointsLowerPlane[i++].y =440.230469;
	imagePointsLowerPlane[i++].y =437.938293;

	return imagePointsLowerPlane;
}

std::vector< std::vector<cv::Point2f> > InitImageCoordCam2()
{
	std::vector< std::vector<cv::Point2f> > imageCoordPoints;

	imageCoordPoints.push_back(InitImageCoordUpperPlaneCam2() );
	imageCoordPoints.push_back(InitImageCoordLowerPlaneCam2() );

	return imageCoordPoints;
}
