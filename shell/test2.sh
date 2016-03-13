#!/bin/bash 

#七中不同的方块的定义
#通过旋转，每种方块的显示的样式可能有几种
box0=(0 0 0 1 1 0 1 1)
box1=(0 2 1 2 2 2 3 2 1 0 1 1 1 2 1 3)
box2=(0 0 0 1 1 1 1 2 0 1 1 0 1 1 2 0)
box3=(0 1 0 2 1 0 1 1 0 0 1 0 1 1 2 1)
box4=(0 1 0 2 1 1 2 1 1 0 1 1 1 2 2 2 0 1 1 1 2 0 2 1 0 0 1 0 1 1 1 2)
box5=(0 1 1 1 2 1 2 2 1 0 1 1 1 2 2 0 0 0 0 1 1 1 2 1 0 2 1 0 1 1 1 2)
box6=(0 1 1 1 1 2 2 1 1 0 1 1 1 2 2 1 0 1 1 0 1 1 2 1 0 1 1 0 1 1 1 2)

#把所有盒子放在box中
box=(${box0[@]} ${box1[@]} ${box2[@]} ${box3[@]} ${box4[@]} ${box5[@]} ${box6[@]})

#每个盒子在box中的偏移
boxOffset=(0 1 3 5 7 11 15)

#旋转次数
rotateCount=(1 2 2 2 4 4 4)

#颜色数组
colourArry=(31 32 33 34 35 36 37)

#选装类型
rotateType=-1

#盒子标号
boxNum=-1

#新盒子
newBox=()

#边缘距离
left=10
top=5

#矩阵的长和宽
widthSize=28
hightSize=26

#确定从矩阵那个地方出来
function ensure_postion()
{
    local sumx=0 i j

    ((minx = ${newBox[0]}))
    ((miny = ${newBox[1]}))
    ((maxy = miny ))
    
    for ((i = 2; i < ${#newBox[*]};i += 2))
    do 
        #确定最小的x坐标
        if ((minx > ${newBox[i]}))
        then
            ((minx = ${newBox[i]}))
        fi
        
        #确定最小的y坐标
        if ((miny > ${newBox[i+1]}))
        then
            ((miny = ${newBox[i+1]}))
        fi

        if ((${newBox[i]} == ${newBox[i-2]}))
        then
            continue
        fi
        
        ((sumx ++))

    done

    if ((sumx == 0))
    then
        ((sumx = 1))
    fi
    
    #当前x,y坐标
    ((currentX = left + widthSize / 2 - sumx * 2 - minx))
    ((currentY = top + 1 - miny))    

    return 0
}

#画出矩阵
function draw_rectangle()
{
    local x y

    echo -e "\033[32m\033[46m\033[1m"

    for ((i = 0 ;i < widthSize;i ++))
    do
        ((x = left + i))
        ((y = top + hightSize - 1))
    
        echo -e "\033[${top};${x}H="
        echo -e "\033[${y};${x}H="

    done

    for ((i = 0 ;i < hightSize;i ++))
    do
        ((x = left + widthSize - 1))
        ((y = top + i))
    
        echo -e "\033[${y};${left}H||"
        echo -e "\033[${y};${x}H||"

    done

    echo -e "\033[0m"
}


#画出方块
function Draw_Box()
{
    local i j x y

    if (($1 == 0))
    then
        for ((i = 0;i < 8;i += 2))
        do
            ((x = currentX + 3 * ${newBox[i]}))
            ((y = currentY + ${newBox[i+1]}))

            echo -e "\033[${y};${x}H "
        done
    else
        echo -e "\033[${colourArry[$colourNum]}m\033[1m"
        for ((i = 0;i < 8;i += 2))
        do
            ((x = currentX + 3 * ${newBox[i]}))
            ((y = currentY + ${newBox[i+1]}))

            echo -e "\033[${y};${x}H[*]"
        done
    fi

    echo -e "\033[0m"
}

#随机产生方块
function Random_Box()
{
    #随机产生盒子号
    (( boxNum = $RANDOM % 7 ))    
    #随机长生盒子的类型
    ((rotateType = $RANDOM % ${rotateCount[boxNum]}))
    #随机产生颜色
    ((colourNum = $RANDOM % ${#colourArry[*]}))

    #找到所在box中的起始位置
    ((j = ${boxOffset[boxNum]} * 8 + rotateType * 8))

    for(( i = 0 ;i < 8;i ++))
    do
        ((newBox[i] = ${box[j+i]}))
    done
}

#判断能否下移
function move_test()
{
    local vary=$1 i
    
    #当前的y坐标加上newBox里面的坐标,其值是否大于28
    for ((i = 0;i < ${#newBox[@]}; i += 2))
    do
        if ((vary + ${newBox[i+1]} > 28))
        then
            return 0
        fi
    done

    return 1
}


draw_rectangle
Random_Box
ensure_postion

while :
do
    Draw_Box 1

    sleep 0.1
    Draw_Box 0

    ((currentY ++))

    if move_test currentY
    then
        Draw_Box 1
        sleep 2
        Draw_Box 0
        Random_Box
        ensure_postion
    fi

done

echo
