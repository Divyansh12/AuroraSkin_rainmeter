[Variables]


; Shorthand bangs and abbreviations
A=!ActivateConfig
S=!SetOptionGroup
SO=!SetOption
SV=!SetVariable
U=!UpdateMeasureGroup
UM=!UpdateMeasure
W=!WriteKeyValue

MA=MatchActions
WV=WriteVariableRounded
V=Variables


; Default audio settings
DefAverageSize=0
DefLoudnessEqualization=1
DefFFTSize=6144
DefFFTOverlap=(#**FFTSize**#-512)
DefFFTAttack=0
DefFFTDecay=240
DefFreqMin=30
DefFreqMax=10000
DefSensitivity=24


; Substitute patterns based on the active type of Setting

StateSubstitute="1":"Display","2":"Audio","3":"Extras","4":"","5":""
SetHeaderTabNames=[#SO# HeaderTab1 Text "Display"][#SO# HeaderTab2 Text "Audio"][#SO# HeaderTab3 Text "Extras"][#SO# HeaderTab4 Text " "][#SO# HeaderTab5 Text " "]

; Name of variable written to file
Var///1="Display":"Bands","Audio":"-1","Extras":"-1"
Var///2="Display":"Width","Audio":"Sensitivity","Extras":"-1"
Var///3="Display":"Height","Audio":"FFTAttack","Extras":"-1"
Var///4="Display":"-1","Audio":"FFTDecay","Extras":"-1"
Var///5="Display":"Scale","Audio":"AverageSize","Extras":"-1"
Var///6="Display":"-1","Audio":"FreqMin","Extras":"-1"
Var///7="Display":"-1","Audio":"FreqMax","Extras":"-1"
Var///8="Display":"-1","Audio":"-1","Extras":"-1"
Var///9="Display":"-1","Audio":"-1","Extras":"-1"
Var///10="Display":"-1","Audio":"-1","Extras":"-1"
Var///11="Display":"-1","Audio":"-1","Extras":"-1"
Var///12="Display":"-1","Audio":"-1","Extras":"-1"
Var///13="Display":"-1","Audio":"-1","Extras":"-1"

; Calc measure MaxValue for Bar meters
CalcMV///1="Display":"128","Audio":"-1","Extras":"-1"
CalcMV///2="Display":"#WORKAREAWIDTH#","Audio":"60","Extras":"-1"
CalcMV///3="Display":"#WORKAREAHEIGHT#","Audio":"500","Extras":"-1"
CalcMV///4="Display":"-1","Audio":"500","Extras":"-1"
CalcMV///5="Display":"5","Audio":"8","Extras":"-1"
CalcMV///6="Display":"-1","Audio":"320","Extras":"-1"
CalcMV///7="Display":"-1","Audio":"24000","Extras":"-1"
CalcMV///8="Display":"-1","Audio":"-1","Extras":"-1"
CalcMV///9="Display":"-1","Audio":"-1","Extras":"-1"
CalcMV///10="Display":"-1","Audio":"-1","Extras":"-1"
CalcMV///11="Display":"-1","Audio":"-1","Extras":"-1"
CalcMV///12="Display":"-1","Audio":"-1","Extras":"-1"
CalcMV///13="Display":"-1","Audio":"-1","Extras":"-1"

; LeftMouseDownAction for String meters
StringLMDA///1="Audio":'[#W# #V# LoudnessEqualization "(#LoudnessEqualization# = 0 ? 1 : 0)" "#@##V#.inc"]',"Extras":'[#A# "#ROOTCONFIG#\Clone"]'
StringLMDA///2="Extras":'[#A# "#ROOTCONFIG#\Clone_2"]'
StringLMDA///3="Extras":'[#A# "#ROOTCONFIG#\SettingsMisc" "ExtrasCreateStandaloneSkin.ini"]'
StringLMDA///4=
StringLMDA///5=
StringLMDA///6="Display":'[#W# #V# Invert "(#Invert# = 0 ? 1 : 0)" "#@##V#.inc"][#W# #V# Invert "(#Invert# = 0 ? 1 : 0)" "#ConfigPath#"]'
StringLMDA///7="Display":'[#W# #V# Flip "(#Flip# = 0 ? 1 : 0)" "#@##V#.inc"][#W# #V# Flip "(#Flip# = 0 ? 1 : 0)" "#ConfigPath#"]'
StringLMDA///8="Display":'[#W# #V# Horizontal "(#Horizontal# = 0 ? 1 : 0)" "#@##V#.inc"][#W# #V# Horizontal "(#Horizontal# = 0 ? 1 : 0)" "#ConfigPath#"]',"Audio":'[#A# "#ROOTCONFIG#\SettingsMisc" "AudioFFTSize.ini"]'
StringLMDA///9="Display":'[#W# #V# SmoothEnds "(#SmoothEnds# = 0 ? 1 : 0)" "#@##V#.inc"]',"Audio":'[#A# "#ROOTCONFIG#\SettingsMisc" "AudioChannel.ini"]'
StringLMDA///10="Audio":'[#A# "#ROOTCONFIG#\SettingsMisc" "AudioMusicPlayer.ini"]'
StringLMDA///11="Audio":'[#W# #V# Port #*PortVariable*# "#@##V#.inc"][#W# #V# Port #*PortVariable*# "#ConfigPath#"]'
StringLMDA///12="Audio":'[#A# "#ROOTCONFIG#\SettingsMisc" "AudioDeviceList.ini"]'
StringLMDA///13="Audio":'[#W# #V# AverageSize #DefAverageSize# "#@##V#.inc"][#W# #V# LoudnessEqualization #DefLoudnessEqualization# "#@##V#.inc"][#W# #V# FFTSize #DefFFTSize# "#@##V#.inc"][#W# #V# FFTOverlap """"#DefFFTOverlap#"""" "#@##V#.inc"][#W# #V# FFTAttack #DefFFTAttack# "#@##V#.inc"][#W# #V# FFTDecay #DefFFTDecay# "#@##V#.inc"][#W# #V# FreqMin #DefFreqMin# "#@##V#.inc"][#W# #V# FreqMax #DefFreqMax# "#@##V#.inc"][#W# #V# Sensitivity #DefSensitivity# "#@##V#.inc"]'

; Display text
Text///1="Display":"Number of peaks: #Bands#","Audio":"#LoudnessEqualization#  Loudness equalization","Extras":"Show duplicate skin...","1  Loudness equalization":"☑  Loudness equalization","#LoudnessEqualization#  Loudness equalization":"☐  Loudness equalization"
Text///2="Display":"Width: #Width# px","Audio":"Sensitivity: #Sensitivity# dB","Extras":"Show duplicate skin (2)..."
Text///3="Display":"Height: #Height# px","Audio":"Attack speed: #FFTAttack# ms","Extras":"Create standalone skin..."
Text///4="Display":"Color:","Audio":"Decay speed: #FFTDecay# ms","Extras":""
Text///5="Display":"Magnification: #Scale#x","Audio":"Smoothness: #AverageSize# past values","Extras":"","1 past values":"1 past value"
Text///6="Display":"#Invert#  Invert spectrum","Audio":"Min frequency: #FreqMin# Hz","Extras":"","1  Invert spectrum":"☑  Invert spectrum","#Invert#  Invert spectrum":"☐  Invert spectrum"
Text///7="Display":"#Flip#  Flip upside down","Audio":"Max frequency: #FreqMax# Hz","Extras":"","1  Flip upside down":"☑  Flip upside down","#Flip#  Flip upside down":"☐  Flip upside down"
Text///8="Display":"#Horizontal#  Horizontal rotation","Audio":"Resolution: #FFTSize# points  ▼","Extras":"","1  Horizontal rotation":"☑  Horizontal rotation","#Horizontal#  Horizontal rotation":"☐  Horizontal rotation"
Text///9="Display":"#SmoothEnds#  Smooth ends","Audio":"Channel: #Channel#  ▼","Extras":"","1  Smooth ends":"☑  Smooth ends","#SmoothEnds#  Smooth ends":"☐  Smooth ends"
Text///10="Display":"","Audio":"Music player: #MusicPlayer#  ▼","Extras":""
Text///11="Display":"","Audio":"Switch to #Port#...","Extras":"","Output":"input","Input":"output"
Text///12="Display":"","Audio":"Set audio device...","Extras":""
Text///13="Display":"","Audio":"Reset audio settings...","Extras":""

; Help text
HelpText///1="Display":"Number of audio bands. Higher values increases precision.","Audio":"Increases visibility for quiet audio sources when applicable.","Extras":"Show a skin clone with separate source options."
HelpText///2="Display":"Spectrum width.","Audio":"Spectrum visibility based on sound level threshold.","Extras":"Show another skin clone with separate source options."
HelpText///3="Display":"Spectrum height.","Audio":"Determines how fast the peaks rise.","Extras":"Create a skin copy with all separate options. (Not related to above)"
HelpText///4="Display":"Change skin color.","Audio":"Determines how fast the peaks fall.","Extras":" "
HelpText///5="Display":"Increases viewing size and performance at the expense of quality.","Audio":"Average sound levels over time to provide continuity.","Extras":" "
HelpText///6="Display":"Reverses the order of the peaks.","Audio":"Threshold for lowest pitched sounds.","Extras":" "
HelpText///7="Display":"Rotates 180°.","Audio":"Threshold for highest pitched sounds.","Extras":" "
HelpText///8="Display":"Rotates 90°.","Audio":"Spectrum accuracy. Note: Higher values will increase delay.","Extras":" "
HelpText///9="Display":"Prevents the output from clipping at the edges.","Audio":"Speaker source.","Extras":" "
HelpText///10="Display":" ","Audio":"Note: When the player is open, all sounds will be displayed.","Extras":" "
HelpText///11="Display":" ","Audio":"Switch between your microphone or speakers.","Extras":" "
HelpText///12="Display":" ","Audio":"Select another audio device.","Extras":" "
HelpText///13="Display":" ","Audio":"Reset audio settings to the default values.","Extras":" "


; Rounding options based on the active type of Setting and Section
RoundDisplayWidthHeight=[#SO# #WV# IfCondition2 "((#***Section***# = 2) || (#***Section***# = 3))"][#SO# #WV# IfTrueAction2 """[#SO# WriteVariable Formula "Round([****#WV#****] / 10) * 10"][#SO# WriteVariable OnChangeAction """[#W# #V# [///#****Section****#] [****WriteVariable****] "#@##V#.inc"][#A# "#ROOTCONFIG#\GenerateBands" "GenerateMeters.ini"]"""]"""]
RoundDisplayBands=[#SO# #WV# IfCondition3 "(#***Section***# = 1)"][#SO# #WV# IfTrueAction3 """[#SO# WriteVariable OnChangeAction """[#W# #V# [///#****Section****#] [****WriteVariable****] "#@##V#.inc"][#A# "#ROOTCONFIG#\GenerateBands" "GenerateMeasures.ini"]"""]"""]
RoundDisplayFinal=[#SO# #WV# IfCondition4 "(#WV# >= 0)"][#SO# #WV# IfTrueAction4 """[#UM# WriteVariable]"""]

RoundDisplay=#RoundDisplayWidthHeight##RoundDisplayBands##RoundDisplayFinal#


; Extra bangs to modify the Settings window based on the active type of Setting

DisplayBangs=#RoundDisplay#[#SO# "4" X 16R][#SO# "4" Y 2r][#SO# "4" W 16][#SO# "4" H 16][#SO# "4" SolidColor #Color#][#SO# "4" LeftMouseUpAction """[!WriteKeyValue Variables WriteVariable Color "#@#Variables.inc"][!ActivateConfig "#ROOTCONFIG#\RGBCode"][!Move "(#**CURRENTCONFIGX**# + [#***CURRENTSECTION***#:X])" "(#**CURRENTCONFIGY**# + [#***CURRENTSECTION***#:Y] + 24)" "#ROOTCONFIG#\RGBCode"]"""]

AudioBangs=[#SO# #MA# String "#Port#"][#UM# #MA#][#SO# #MA# IfMatch "Output"][#SO# #MA# IfMatchAction """[#SV# PortVariable "Input"]"""][#SO# #MA# IfMatch2 "Input"][#SO# #MA# IfMatchAction2 """[#SV# PortVariable "Output"]"""][#UM# #MA#]

ExtrasBangs=

IfMatchDisplay=[#SO# #MA# IfMatch "Display"][#SO# #MA# IfMatchAction """#DisplayBangs#"""]
IfMatchAudio=[#SO# #MA# IfMatch2 "Audio"][#SO# #MA# IfMatchAction2 """#AudioBangs#"""]
IfMatchExtras=[#SO# #MA# IfMatch3 "Extras"][#SO# #MA# IfMatchAction3 """#ExtrasBangs#"""]
SetOptionsByState=[#SO# #MA# String [StateReference]][#UM# #MA#]#IfMatchDisplay##IfMatchAudio##IfMatchExtras#[#UM# #MA#]
