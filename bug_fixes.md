# Bug Fix Tasks #

Tasks from testing
  * remove commented out code - Everyone
  * try to fix compile warnings - Everyone
  * crash when switching tabs in shapeCreate mode
    * fixed - ckb
  * Toolbar drop down menus don't update when tabs are switched. None is always checked.
    * semi-fixed - ckb
  * RoundedSquare not added to Toolbar::canvasSync()
    * fixed - ckb
  * Extend and Include lines in Use Case Diagram aren't in Toolbar::canvasSync()
    * Extend line fixed.  We need a new type for Include line. - ckb
  * classbox width not loading properly
    * fixed: width now loads properly - cabljohn
  * get\_all and split\_all using wrong member variables, sort of breaking under the hood
    * fixed: now uses the correct member variables - cabljohn