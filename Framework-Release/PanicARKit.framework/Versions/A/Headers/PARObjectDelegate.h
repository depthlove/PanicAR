//
//  PARObjectDelegate.h
//  ArchiApp
//
//  Created by Andreas Zeitler on 05.06.11.
//  Copyright 2011 doPanic. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>
#import "PSKMath.h"

#define CLIP_AT_ANGLE_DEVIATION 35
#define HEAVY_SMOOTH 10
#define LIGHT_SMOOTH 5

@class PARView;
@class PARRadarView;

/*! @protocol PARObjectDelegate */
@protocol PARObjectDelegate

/*! title of the object */
- (NSString *)title;

/*! callback to object when it is added to the PARController via addObject */
- (void)addedToARController;
/*! callback to object when it is removed from the PARController via removeObject */
- (void)removedFromARController;

/*! @return YES when object is hidden */
- (BOOL)hidden;

/*! unload content when PARView is unloaded */
- (void)unloadContent;
/*! load content when PARView is loaded or displayed and content is not yet loaded */
- (void)loadContent;

/*! call on location update */
- (void)updateLocation;
/*! call when distance has changed and content needs to be update (e.g. distanc string) */
- (void)updateContent;
/*! call to chance appearance based on distance, e.g. fade out, make smaller */
- (void)updateAppearance;

/*! handles the rendering in the PARView
 @param theView PARView the object will be rendered in */
- (void)renderInView:(PARView *)theView;
/*! handles the rendering in the PARRadarView
 @param theRadar PARRadarView the object will be rendered in */
- (void)renderInRadar:(PARRadarView *)theRadar;

/*! angle to camera
 @remarks used internally */
- (float)angleToCamera;
/*! coordinates in virtual space around camera
 @remarks used internally */
- (PSKVector3)virtualPosition;
/*! distance to user
 @remarks used internally */
- (float)distanceToUser;

/*! location of this object
 @return CLLocation */
- (CLLocation*)location;
/*! set location of this object
 @remarks be careful updating the location of existing labels 
 @param theLocation CLLocation location */
- (void)setLocation:(CLLocation *)theLocation;

/*! latitude of this object */
- (float)latitude;
/*! longitude of this object */
- (float)longitude;
/*! altitude of this object */
- (float)altitude;
/*! heading, i.e. rotation offset in relation to north pole, of this object */
- (float)heading;

@end