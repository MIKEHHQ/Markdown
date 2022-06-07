# USART通信

## 描述

复位后发生对应字符

## 软件

CUBEMX + KEIL
LL 库

## 注意事项

1. 发生BUG:复位后发送第一位数据丢失。

分析：应该是寄存器问题。

```C
int fputc(int ch,FILE *f)
{
	LL_USART_TransmitData8(USART1, ch);

	while(!LL_USART_IsActiveFlag_TC(USART1))
	{

	}
	return ch;
}
```

修改为LL_USART_IsActiveFlag_TXE的判断可以解决问题。

```C
int fputc(int ch,FILE *f)
{
	LL_USART_TransmitData8(USART1, ch);

	while(!LL_USART_IsActiveFlag_TXE(USART1))
	{

	}
	return ch;
}
```

网上分析具体原因为stm32的usart的sr寄存器的TC为初始为1，导致第一次打印时的第一个数据被覆盖，所以打印不出。
2. 没有接受到数据。
STM32自己作为主机
解决方法：在Option中将Target中的 Use MicroLIB选上。
3. LL库发送API

```C
__STATIC_INLINE void LL_USART_TransmitData8(USART_TypeDef *USARTx, uint8_t Value)
{
  USARTx->DR = Value;
}
```

可以看到是相比HAL库简单的。

3. 方便的串口读写

```c
//这样就可以使用printf函数了
int fputc(int ch, FILE *f)
{
		USART_SendData(USARTx, (uint8_t) ch);

		while (USART_GetFlagStatus(USARTx, USART_FLAG_TXE) == RESET);

		return (ch);
}

//这样就可以使用scanf,getchar函数了
int fgetc(FILE *f)
{
		while (USART_GetFlagStatus(USARTx, USART_FLAG_RXNE) == RESET);

		return (int)USART_ReceiveData(USARTx);
}

```

## END

最后还是加上了回环的功能。
