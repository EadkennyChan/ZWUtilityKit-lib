//
//  ZWTableViewCell.h
//  SuperCode
//
//  Created by chenpeng on 16/5/3.
//  Copyright © 2016年 chenzw. All rights reserved.
//

#import <UIKit/UIKit.h>

UIKIT_EXTERN NSString *const ZWSeperatorLineCellID;
/*
 *  @brief： 分割线管理cell
 */
@interface ZWSeperatorLineCell : UITableViewCell

- (void)showTopSeparatorLine:(BOOL)bShow color:(UIColor *)color;
- (void)showTopSeparatorLine:(BOOL)bShow color:(UIColor *)color indent:(CGFloat)fIndent;
- (void)showBottomSeparatorLine:(BOOL)bShow color:(UIColor *)color;
- (void)showBottomSeparatorLine:(BOOL)bShow color:(UIColor *)color indent:(CGFloat)fIndent;

@end

/*
 *  @brief：左边是否显示红色*以表明是否必填
 *      右边是否显示箭头之类的提示
 */
@interface ZWRequiredTipCell : UITableViewCell

@property (nonatomic, retain, readonly)UILabel *labelRequired;
@property (nonatomic, assign)CGFloat fRequiredTipWidth;//
@property (nonatomic, assign)CGFloat fAccessoryWidth;//

//是否显示必填项提示符（红色*）
- (void)showRequiredTip:(BOOL)bShow;
- (void)showAccessoryImage:(BOOL)bShow image:(UIImage *)image;

@end

#pragma mark -

typedef NS_ENUM(NSInteger, VerticalAlignment)
{
    VerticalAlignment_Middle = 0, // default
    VerticalAlignment_Top,
    VerticalAlignment_Bottom
};

UIKIT_EXTERN NSString *const ZWLabelTipCellID;

@interface ZWLabelTipCell : ZWSeperatorLineCell

@property (nonatomic, retain, readonly)UILabel *labelTip;
@property (nonatomic, assign)VerticalAlignment alignmentTipVertical;
@property (nonatomic, assign)CGFloat fWidthTip;

//是否现在必填项提示符（红色*）
- (void)showRequiredTip:(BOOL)bShow;
- (void)showAccessory:(BOOL)bShow image:(NSString *)strImage;

@end

UIKIT_EXTERN NSString *const ZWLabelLabelCellID;

@interface ZWLabelLabelCell : ZWLabelTipCell
@property (nonatomic, retain, readonly)UILabel *labelContent;

@end

#pragma mark -

@protocol ZWLabelTFDelegate;

UIKIT_EXTERN NSString *const ZWLabelTFCellID;

@interface ZWLabelTFCell : ZWLabelTipCell

@property (nonatomic, retain, readonly)UITextField *tfContent;
@property (nullable, nonatomic, weak)id<ZWLabelTFDelegate> delegate;

@end

@protocol ZWLabelTFDelegate <NSObject>

- (void)labelTfDidEndEditing:(nonnull ZWLabelTFCell *)labelTF;

@end
