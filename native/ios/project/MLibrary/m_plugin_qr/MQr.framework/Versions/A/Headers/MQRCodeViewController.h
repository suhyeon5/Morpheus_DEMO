//
//  MQRCodeViewController.h
//

typedef void(^MQRCodeViewControllerTakeHandler)(NSDictionary *data, BOOL cancelled, BOOL closed);


typedef NS_ENUM(NSInteger, MQrFilterType) {
    MQrFilterTypeNone = 0,
    MQrFilterTypePartial = 1,
//    MQrFilterTypeEan2 = 2,
//    MQrFilterTypeEan5 = 5,
    MQrFilterTypeEan8 = 8,
    MQrFilterTypeUpce = 9,
    MQrFilterTypeIsbn10 = 10,
    MQrFilterTypeUpca = 12,
    MQrFilterTypeEan13 = 13,
    MQrFilterTypeIsbn13 = 14,
//    MQrFilterTypeComposite = 15,
    MQrFilterTypeI25 = 25,
    MQrFilterTypeDatabar = 34,
    MQrFilterTypeDatabar_exp = 35,
    MQrFilterTypeCodabar = 38,
    MQrFilterTypeCode39 = 39,
    MQrFilterTypePdf417 = 57,
    MQrFilterTypeQrcode = 64,
    MQrFilterTypeCode93 = 93,
    MQrFilterTypeCode128 = 128
};

@interface NSString(MQRCodeViewController)

- (MQrFilterType)filterTypeFromString;

@end

@interface MQRCodeViewController : PPNativeViewController

@property (nonatomic, strong) IBOutlet UIView *captureView;
@property (nonatomic, strong) IBOutlet UIView *userInterfaceView;
@property (nonatomic, strong) IBOutlet UILabel *titleLabel;
@property (nonatomic, strong) IBOutlet UIButton *cancelButton;
@property (nonatomic, strong) IBOutlet UIButton *flashButton;
@property (nonatomic, readwrite) MQrFilterType filterType;
@property (nonatomic, retain) NSArray *filterTypes;
@property (nonatomic, readwrite) CGSize captureScale;

@property (nonatomic, readwrite) BOOL useGuideLine;
@property (nonatomic, readwrite, getter=isFlashOn) BOOL flashOn;
@property (nonatomic, readwrite, getter=isFadeToggle) BOOL fadeToggle;
@property (nonatomic, readonly, getter=isScanned) BOOL scanned;
@property (nonatomic, strong) MQRCodeViewControllerTakeHandler takeHandler;

- (BOOL)useGuideLine;
- (void)setUseGuideLine:(BOOL)useGuideLine;
- (void)setFlashOn:(BOOL)flashOn;
- (void)setUserInterfaceOn:(BOOL)userInterfaceOn;
- (IBAction)onClickCancelButton:(id)sender;
- (IBAction)onToggleFlashButton:(id)sender;
- (void)readerStop;
- (void)readerStart;
- (void)close:(NSDictionary *)data cancelled:(BOOL)cancelled;

//EX
@property (nonatomic, strong) IBOutlet UIView *tempView1;
@property (nonatomic, strong) IBOutlet UIView *tempView2;
@property (nonatomic, strong) IBOutlet UILabel *tempLabel1;
@property (nonatomic, strong) IBOutlet UILabel *tempLabel2;
@property (nonatomic, strong) IBOutlet UIButton *tempButton1;
@property (nonatomic, strong) IBOutlet UIButton *tempButton2;
- (IBAction)onClickTempButton1:(id)sender;
- (IBAction)onClickTempButton2:(id)sender;


@end
