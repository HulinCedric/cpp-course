# Microsoft Developer Studio Project File - Name="AgenceBancaire" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=AgenceBancaire - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "AgenceBancaire.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "AgenceBancaire.mak" CFG="AgenceBancaire - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "AgenceBancaire - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "AgenceBancaire - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "AgenceBancaire - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x40c /d "NDEBUG"
# ADD RSC /l 0x40c /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "AgenceBancaire - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE RSC /l 0x40c /d "_DEBUG"
# ADD RSC /l 0x40c /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "AgenceBancaire - Win32 Release"
# Name "AgenceBancaire - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AgenceBancaire_0_1.cpp

!IF  "$(CFG)" == "AgenceBancaire - Win32 Release"

!ELSEIF  "$(CFG)" == "AgenceBancaire - Win32 Debug"

# ADD CPP /GR

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\AgenceBancaire_0_2.cpp

!IF  "$(CFG)" == "AgenceBancaire - Win32 Release"

!ELSEIF  "$(CFG)" == "AgenceBancaire - Win32 Debug"

# ADD CPP /GR

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\AgenceBancaire_1.cpp

!IF  "$(CFG)" == "AgenceBancaire - Win32 Release"

!ELSEIF  "$(CFG)" == "AgenceBancaire - Win32 Debug"

# ADD CPP /GR

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\AgenceBancaire_2_2.cpp

!IF  "$(CFG)" == "AgenceBancaire - Win32 Release"

!ELSEIF  "$(CFG)" == "AgenceBancaire - Win32 Debug"

# ADD CPP /GR

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\AgenceBancaire_2_3.cpp

!IF  "$(CFG)" == "AgenceBancaire - Win32 Release"

!ELSEIF  "$(CFG)" == "AgenceBancaire - Win32 Debug"

# ADD CPP /GR

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\AgenceBancaire_3_1.cpp

!IF  "$(CFG)" == "AgenceBancaire - Win32 Release"

!ELSEIF  "$(CFG)" == "AgenceBancaire - Win32 Debug"

# ADD CPP /GR

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\AgenceBancaire_3_2.cpp

!IF  "$(CFG)" == "AgenceBancaire - Win32 Release"

!ELSEIF  "$(CFG)" == "AgenceBancaire - Win32 Debug"

# ADD CPP /GR

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\AgenceBancaire_3_3.cpp

!IF  "$(CFG)" == "AgenceBancaire - Win32 Release"

!ELSEIF  "$(CFG)" == "AgenceBancaire - Win32 Debug"

# ADD CPP /GR

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\AgenceBancaire_3_4.cpp

!IF  "$(CFG)" == "AgenceBancaire - Win32 Release"

!ELSEIF  "$(CFG)" == "AgenceBancaire - Win32 Debug"

# ADD CPP /GR

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\AgenceBancaire_3_5.cpp

!IF  "$(CFG)" == "AgenceBancaire - Win32 Release"

!ELSEIF  "$(CFG)" == "AgenceBancaire - Win32 Debug"

# ADD CPP /GR

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\AgenceBancaire_4_1.cpp

!IF  "$(CFG)" == "AgenceBancaire - Win32 Release"

!ELSEIF  "$(CFG)" == "AgenceBancaire - Win32 Debug"

# ADD CPP /GR

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\AgenceBancaire_4_2_1.cpp

!IF  "$(CFG)" == "AgenceBancaire - Win32 Release"

!ELSEIF  "$(CFG)" == "AgenceBancaire - Win32 Debug"

# ADD CPP /GR

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\AgenceBancaire_4_2_2.cpp

!IF  "$(CFG)" == "AgenceBancaire - Win32 Release"

!ELSEIF  "$(CFG)" == "AgenceBancaire - Win32 Debug"

# ADD CPP /GR

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\AgenceBancaire_4_2_3.cpp

!IF  "$(CFG)" == "AgenceBancaire - Win32 Release"

!ELSEIF  "$(CFG)" == "AgenceBancaire - Win32 Debug"

# ADD CPP /GR

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\AgenceBancaire_4_3_1.cpp

!IF  "$(CFG)" == "AgenceBancaire - Win32 Release"

!ELSEIF  "$(CFG)" == "AgenceBancaire - Win32 Debug"

# ADD CPP /GR

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\AgenceBancaire_4_3_2.cpp

!IF  "$(CFG)" == "AgenceBancaire - Win32 Release"

!ELSEIF  "$(CFG)" == "AgenceBancaire - Win32 Debug"

# ADD CPP /GR

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\AgenceBancaire_4_3_3.cpp

!IF  "$(CFG)" == "AgenceBancaire - Win32 Release"

!ELSEIF  "$(CFG)" == "AgenceBancaire - Win32 Debug"

# ADD CPP /GR

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\AgenceBancaire_4_4.cpp

!IF  "$(CFG)" == "AgenceBancaire - Win32 Release"

!ELSEIF  "$(CFG)" == "AgenceBancaire - Win32 Debug"

# ADD CPP /GR

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\AgenceBancaire_4_5.cpp

!IF  "$(CFG)" == "AgenceBancaire - Win32 Release"

!ELSEIF  "$(CFG)" == "AgenceBancaire - Win32 Debug"

# ADD CPP /GR

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\AgenceBancaire_P.cpp
# End Source File
# Begin Source File

SOURCE=.\T_AgenceBancaire_P.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AgenceBancaire.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Group "_Banque"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\_Banque\Debug\_Banque_0.obj
# End Source File
# Begin Source File

SOURCE=..\_Banque\Debug\_Banque_1.obj
# End Source File
# Begin Source File

SOURCE=..\_Banque\Debug\_Banque_2.obj
# End Source File
# Begin Source File

SOURCE=..\_Banque\Debug\_Banque_3_1.obj
# End Source File
# Begin Source File

SOURCE=..\_Banque\Debug\_Banque_3_2.obj
# End Source File
# Begin Source File

SOURCE=..\_Banque\Debug\_Banque_3_3.obj
# End Source File
# Begin Source File

SOURCE=..\_Banque\Debug\_Banque_3_4.obj
# End Source File
# Begin Source File

SOURCE=..\_Banque\Debug\_Banque_3_5.obj
# End Source File
# Begin Source File

SOURCE=..\_Banque\Debug\_Banque_4.obj
# End Source File
# End Group
# Begin Group "Collection"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\_Maths\Collection\Debug\Collection_1.obj
# End Source File
# Begin Source File

SOURCE=..\..\_Maths\Collection\Debug\Collection_3_1.obj
# End Source File
# Begin Source File

SOURCE=..\..\_Maths\Collection\Debug\Collection_3_2.obj
# End Source File
# Begin Source File

SOURCE=..\..\_Maths\Collection\Debug\Collection_3_3.obj
# End Source File
# Begin Source File

SOURCE=..\..\_Maths\Collection\Debug\Collection_4.obj
# End Source File
# End Group
# Begin Group "CompteBancaire"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\CompteBancaire\Debug\CompteBancaire_0.obj
# End Source File
# Begin Source File

SOURCE=..\CompteBancaire\Debug\CompteBancaire_1.obj
# End Source File
# Begin Source File

SOURCE=..\CompteBancaire\Debug\CompteBancaire_2_2.obj
# End Source File
# Begin Source File

SOURCE=..\CompteBancaire\Debug\CompteBancaire_2_3.obj
# End Source File
# Begin Source File

SOURCE=..\CompteBancaire\Debug\CompteBancaire_3_1.obj
# End Source File
# Begin Source File

SOURCE=..\CompteBancaire\Debug\CompteBancaire_3_2.obj
# End Source File
# Begin Source File

SOURCE=..\CompteBancaire\Debug\CompteBancaire_P.obj
# End Source File
# End Group
# Begin Group "CompteCourant"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\CompteCourant\Debug\CompteCourant_1.obj
# End Source File
# Begin Source File

SOURCE=..\CompteCourant\Debug\CompteCourant_2.obj
# End Source File
# Begin Source File

SOURCE=..\CompteCourant\Debug\CompteCourant_3_1.obj
# End Source File
# Begin Source File

SOURCE=..\CompteCourant\Debug\CompteCourant_3_2.obj
# End Source File
# Begin Source File

SOURCE=..\CompteCourant\Debug\CompteCourant_P.obj
# End Source File
# End Group
# Begin Group "CompteEpargne"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\CompteEpargne\Debug\CompteEpargne_1.obj
# End Source File
# Begin Source File

SOURCE=..\CompteEpargne\Debug\CompteEpargne_2.obj
# End Source File
# Begin Source File

SOURCE=..\CompteEpargne\Debug\CompteEpargne_3.obj
# End Source File
# Begin Source File

SOURCE=..\CompteEpargne\Debug\CompteEpargne_4_1.obj
# End Source File
# Begin Source File

SOURCE=..\CompteEpargne\Debug\CompteEpargne_4_2.obj
# End Source File
# Begin Source File

SOURCE=..\CompteEpargne\Debug\CompteEpargne_5.obj
# End Source File
# Begin Source File

SOURCE=..\CompteEpargne\Debug\CompteEpargne_P.obj
# End Source File
# End Group
# Begin Group "OperationBancaire"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\OperationBancaire\Debug\OperationBancaire_1.obj
# End Source File
# Begin Source File

SOURCE=..\OperationBancaire\Debug\OperationBancaire_2.obj
# End Source File
# Begin Source File

SOURCE=..\OperationBancaire\Debug\OperationBancaire_P.obj
# End Source File
# End Group
# Begin Group "Titulaire"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\Titulaire\Debug\Titulaire_1.obj
# End Source File
# Begin Source File

SOURCE=..\Titulaire\Debug\Titulaire_2.obj
# End Source File
# Begin Source File

SOURCE=..\Titulaire\Debug\Titulaire_3.obj
# End Source File
# Begin Source File

SOURCE=..\Titulaire\Debug\Titulaire_P.obj
# End Source File
# End Group
# Begin Group "Tests"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\_Tests\Tests\Debug\Tests.obj
# End Source File
# Begin Source File

SOURCE=..\..\_Tests\Tests\Debug\Tests_1.obj
# End Source File
# Begin Source File

SOURCE=..\..\_Tests\Tests\Debug\Tests_2.obj
# End Source File
# End Group
# Begin Group "_archive"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\_Archives\_Archives\Debug\_Archives.obj
# End Source File
# End Group
# Begin Group "archive"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\_Archives\Archive\Debug\Archive.obj
# End Source File
# Begin Source File

SOURCE=..\..\_Archives\Archive\Debug\Archive_1_1.obj
# End Source File
# Begin Source File

SOURCE=..\..\_Archives\Archive\Debug\Archive_1_2.obj
# End Source File
# Begin Source File

SOURCE=..\..\_Archives\Archive\Debug\Archive_1_3.obj
# End Source File
# Begin Source File

SOURCE=..\..\_Archives\Archive\Debug\Archive_1_4.obj
# End Source File
# End Group
# Begin Group "file"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\_Archives\File\Debug\File.obj
# End Source File
# End Group
# Begin Group "object"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\_Archives\Object\Debug\Object.obj
# End Source File
# End Group
# End Group
# End Target
# End Project
