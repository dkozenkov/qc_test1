#ifndef MSG_CONST_H
#define MSG_CONST_H

#ifndef NULL
#define NULL ((void*)0)
#endif

#ifndef TRUE
#define TRUE 1
#endif

#ifndef FALSE
#define FALSE 0
#endif

/* typedefs that indicates size and signedness */

typedef char                CHAR;     /*  8-bit plain char used for character data */
typedef float               FLOAT32;  /* 32-bit floating point */
typedef double              FLOAT64;  /* 64-bit extended floating point */

typedef signed char         INT8;     /*  8-bit signed integer, used for numeric data */
typedef signed short        INT16;    /* 16-bit signed integer */
typedef signed int          INT32;    /* 32-bit signed integer */
typedef signed long long    INT64;    /* 64-bit signed integer */

typedef unsigned char       UINT8;    /*  8-bit unsigned integer, used for numeric data */
typedef unsigned short int  UINT16;   /* 16-bit unsigned integer */
typedef unsigned int        UINT32;   /* 32-bit unsigned integer */
typedef unsigned long long  UINT64;   /* 64-bit unsigned integer */
typedef UINT8               BOOLEAN;

/**
 * @brief максимальное кол-во байт в одном сообщении
 */
#define MAX_MSG_SIZE 4089

/**
 * @brief кол-во байт в квитирующем сообщении
 */
#define ACK_SIZE 4

/**
 * @brief кол-во байт в data-сообщении до начала payload
 */
#define PRE_SIZE 4

// 2.2.1	Поле TYPE состоит из набора бит, конкретизирующих тип сообщения:
typedef enum TYPE {
    TYPE_DATA  = 0x80, // Сообщение с payload, требующее подтверждения ACK
    TYPE_ACK   = 0x40, // Уведомление о приёме валидного сообщения
    TYPE_BUSY  = 0x20, // Уведомление о занятости получателя
    TYPE_E_PL  = 0x10, // Уведомление о приёме сообщения с невалидным содержимым payload
    TYPE_E_CRC = 0x08, // Уведомление о приёме сообщения с невалидным CRC
    TYPE_E_STR = 0x04, // Уведомление о приёме сообщения c неверной структурой или истекло время ожидания приёма сообщения
    TYPE_DATA_NO_ACK = 0x02 // Сообщение с payload, не требующее подтверждения ACK
} MsgType;

char *get_type_desc(MsgType type);

#endif
