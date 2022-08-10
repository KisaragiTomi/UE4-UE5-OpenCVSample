// Fill out your copyright notice in the Description page of Project Settings.


#include "CV_ImageReader.h"
#include "Engine/Engine.h"
#include "Misc/Paths.h"
#include  <stdio.h>
#include "Runtime/Core/Public/HAL/Runnable.h"
#include "Runtime/Core/Public/HAL/RunnableThread.h"

#if PLATFORM_WINDOWS
#include  <direct.h>
#endif


#include <string>
#include "GenericPlatform/GenericPlatformFile.h"
#include "HAL/PlatformFilemanager.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/core.hpp"
#include "opencv2/highgui.hpp"	
#include "opencv2/imgproc.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/ximgproc.hpp"


using namespace cv;
using namespace std;
using namespace cv::ximgproc;
// Sets default values
ACV_ImageReader::ACV_ImageReader()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void ACV_ImageReader::BeginPlay()
{
	Super::BeginPlay();

#if PLATFORM_WINDOWS
	FString ContentPath = FPaths::ProjectPluginsDir() + TEXT("OpenCV_Plugin/Content/Asset/Texture");
	FString TestImgPath = FPaths::Combine(ContentPath, TEXT("LittlePig.png"));
	IPlatformFile& PlatformFile = FPlatformFileManager::Get().GetPlatformFile();
	if (!PlatformFile.FileExists(*TestImgPath))
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, FString::Printf(TEXT("TestImgPath == %s not exist "), *TestImgPath));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Green, FString::Printf(TEXT("TestImgPath == %s exist "), *TestImgPath));
	}
	//using namespace cv;
	
	string temp(TCHAR_TO_UTF8(*TestImgPath));

	Mat img = imread(temp, IMREAD_UNCHANGED);
	FString ts = ContentPath + "TestRes/ttwin.jpeg";
	imwrite(TCHAR_TO_UTF8(*ts), img);

	namedWindow("Example", WINDOW_AUTOSIZE);
	imshow("Example", img);


#endif
	
}

// Called every frame
void ACV_ImageReader::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

