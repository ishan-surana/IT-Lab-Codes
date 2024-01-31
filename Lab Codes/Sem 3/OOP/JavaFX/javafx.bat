@echo on
setlocal enabledelayedexpansion

rem Set the path to JavaFX libraries
set javafxPath=C:\Program Files\Java\javafx-sdk-21.0.1\lib

rem Get the first argument (Java class file) provided to the batch file
set javaFile=%1

rem Check if a file is provided
if "%javaFile%"=="" (
    echo Usage: javafx.bat <JavaClassFile>
    exit /b 1
)

rem Run the Java program with the specified JavaFX arguments
java --module-path "%javafxPath%" --add-modules javafx.controls,javafx.fxml %javaFile% %*

endlocal