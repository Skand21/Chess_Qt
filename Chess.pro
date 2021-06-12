QT += quick
QT += widgets
CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp \
    fd_boardChess.cpp \
    fd_buttons.cpp \
    fd_chessBox.cpp \
    fd_chesspiece.cpp \
    game.cpp \
    piece_bishop.cpp \
    piece_king.cpp \
    piece_knight.cpp \
    piece_pawn.cpp \
    piece_queen.cpp \
    piece_rook.cpp

HEADERS  += \
    fd_boardChess.h \
    fd_buttons.h \
    fd_chessBox.h \
    fd_chessPiece.h \
    game.h \
    piece_bishop.h \
    piece_king.h \
    piece_knight.h \
    piece_pawn.h \
    piece_queen.h \
    piece_rook.h


RESOURCES += \
    resource.qrc

DISTFILES +=
