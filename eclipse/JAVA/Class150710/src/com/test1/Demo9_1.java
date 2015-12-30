/*
 * 功能:Java绘图原理
 * 
 */

package com.test1;
import javax.swing.*;
import java.awt.*;
public class Demo9_1  extends JFrame{
		
			MyPanel mp=null;
			public static void main(String[] args) {
				// TODO Auto-generated method stub
				Demo9_1 demo9_1 = new Demo9_1();
		
			}
			
			public Demo9_1()
			{
				mp =  new MyPanel();
				
				this.add(mp);
				
				this.setSize(400, 300);
				this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				this.setVisible(true);
			}

}

//定义MyPanel(我自己的面板,  用于绘图和现实绘图的区域)
class MyPanel extends JPanel
{
	//覆盖JPanel的paint函数
	//Graphics 是绘图的重要类,可以理解为画笔
	public void paint(Graphics g){
		//调用父类函数完成初始化
		super.paint(g);
		//先画一个圆
		//g.drawOval(10, 10, 30, 30);
		//直线
		//g.drawLine(10,10,40,40);
		//矩形边框
		//g.drawRect(10, 10, 40, 60);
		//填充矩形
		g.setColor(Color.BLUE);
		g.fillRect(10,10,40,60);
		g.setColor(Color.RED);
		g.fillRect(70,70,40,60);
	}
}

















