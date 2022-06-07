# Markdown
---

## Introduction

This is my sample project in EE.
Except this,
This is a repositories of Markdown examples.
Try Markdown on VSCode, etc.

## Code

```python
print(
    Hello Markdown!
)
```
# Table
| Name | 
| ---- |

## Mermaid

```mermaid
graph TD;
    A-->B;
    A-->C;
    A-->D;
    M-->H;
    B-->F;
    B-->G;
    G-->F
    C-->H;
```

```mermaid
graph LR;
a==>b;
b-->c;
a--联系-->c;
a-->s;
a-.->f;
s-->j;
c---id2;

subgraph 图表名;
        id2[默认方形]==粗线==>id3{菱形}
        id3-.虚线.->id4>右向旗帜]
        id3--无箭头---id5((圆形))
    end
```

```mermaid
sequenceDiagram
    participant Alice
    participant Bob
    Alice->>John: Hello John, how are you?
    loop Healthcheck
        John->>John: Fight against hypochondria
    end
    Note right of John: Rational thoughts <br/>prevail...
    John-->>Alice: Great!
    John->>Bob: How about you?
    Bob-->>John: Jolly good!
```

![[pic.png]]


```mermaid
gantt
    dateFormat  YYYY-MM-DDenhancedmarkdown
    title 为Mermaid加入甘特图功能
    section A部分
    完成任务        :crit,done, des1,2019-01-06,2019-01-08
    正进行任务      :active, des2,2019-01-09,3d
    待开始任务      :des3, after des2, 5d
    待开始任务2     :des4, after des3, 5d
    section 紧急任务
    完成任务        :crit,done,2019-01-06,24h
    实现parser     :crit,done,after des1, 2d
    为parser编写test :crit, active, 3d
    待完成任务      :crit,5d
    为rendere编写test: 2d
    将功能加入到mermaid: 1d
```

