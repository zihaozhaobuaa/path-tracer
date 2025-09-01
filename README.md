# net-trace (C++20 skeleton)

一个用于电连通/版图追踪类竞赛的 **C++20 / CMake** 代码库骨架。默认生成单一可执行程序 `trace`，命令行为：

```
trace -layout <layout.txt> -rule <rule.txt> [-thread n] -output <result.txt>
```

> 本仓库目前提供**可编译的骨架**与最小实现（解析/算法留空），方便你直接在此基础上迭代。  
> - 未指定 `-thread` 时强制 1 线程；指定 `-thread n` 时绝不超过 n。  
> - 输出目前为占位文本，请按赛题需要自行实现。

## 快速开始
```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j
./build/trace -layout data/sample_layout.txt -rule data/sample_rule_1.txt -output out.txt
```

## 目录结构
见仓库根目录的 `src/`、`scripts/`、`data/` 等。`src/trace` 和 `src/geom` 中的头文件已经为你留好实现接口与 TODO。

## 许可证
MIT

## 目录结构

```
net-trace/
├─ CMakeLists.txt
├─ cmake/
│  ├─ toolchains/                # 可选：交叉编译/特定编译器设置
│  └─ sanitizer.cmake            # ASan/UBSan/TSan 便捷开关
├─ src/
│  ├─ main.cpp                   # 解析 CLI，调度 TracePipeline
│  ├─ cli/args.h                 # 轻量参数解析（无三方依赖）
│  ├─ core/
│  │  ├─ types.h                 # 别名：LayerId, PolyId, Point{int32}, Box 等
│  │  ├─ layout_model.h          # Layout、Layer、Polygon 的内存结构
│  │  ├─ rule_model.h            # StartPos、ViaRule（分段相邻）、GateRule(PO,AA)
│  │  └─ result_model.h          # 按层分组的输出表示，CCW 顶点序校验
│  ├─ io/
│  │  ├─ layout_reader.h/.cpp    # 读取“Layer 标识 + 多边形顶点(逆时针)”文本
│  │  ├─ rule_reader.h/.cpp      # 读取 StartPos/Via/Gate 文本规则
│  │  └─ result_writer.h/.cpp    # 写出结果文本，稳定排序/去重
│  ├─ geom/
│  │  ├─ manhattan_poly.h/.cpp   # 曼哈顿多边形基础：规范化、包围盒、CCW
│  │  ├─ intersect.h/.cpp        # 面积重叠/边界点/边界线相交（赛题三种）
│  │  ├─ point_in_poly.h/.cpp    # 点在多边形（含边界）判定
│  │  ├─ grid_index.h/.cpp       # 简易网格/桶索引加速跨层/同层相交候选
│  │  └─ cutter.h/.cpp           # AA 被 PO 贯穿后的切割（保证切成两部分）
│  ├─ trace/
│  │  ├─ via_graph.h/.cpp        # 仅在“相邻层”建立交叠连边，忽略非相邻
│  │  ├─ ufds.h/.cpp             # 并查集/连通分量（同层 + 相邻层 via 合并）
│  │  ├─ flood_fill.h/.cpp       # 从起点所属多边形出发的检索（BFS/DFS）
│  │  ├─ gate_rule.h/.cpp        # s1 驱动 PO 高电平集合、AA 跨 PO 的连通裁决
│  │  └─ pipeline.h/.cpp         # TracePipeline：解析→预处理→连通→输出
│  ├─ parallel/
│  │  ├─ thread_pool.h/.cpp      # 固定线程池，严格不超 -thread 指定
│  │  └─ par_algos.h/.cpp        # for_each_parallel、并行构建相交对
│  └─ utils/
│     ├─ span.h                  # 轻量视图（避免拷贝）
│     ├─ timer.h                 # 计时/性能日志
│     ├─ logging.h               # LOG_xxx 宏（可通过编译选项开关）
│     └─ small_vec.h             # 小向量优化（避免频繁分配）
├─ include/                      # 若需对外头文件可放这里（可留空）
├─ tests/
│  ├─ CMakeLists.txt
│  ├─ test_parser.cpp
│  ├─ test_intersect.cpp
│  ├─ test_cutter.cpp
│  └─ test_trace.cpp
├─ bench/
│  └─ micro_bench.cpp            # 小基准：相交/索引/并查集
├─ data/
│  ├─ sample_layout.txt          # 自带小样例，用于单元测试
│  ├─ sample_rule_1.txt          # 子题一
│  ├─ sample_rule_2.txt          # 子题二（含多 Via）
│  └─ sample_rule_3.txt          # 子题三（含 Gate: PO, AA）
├─ scripts/
│  ├─ build.sh                   # 统一构建（Debug/Release/ASan）
│  ├─ run.sh                     # 包装命令行：trace -layout ... -rule ... -output ...
│  ├─ perf_single.sh             # 单线程跑分，符合“未指定 -thread 时禁多线程”
│  └─ perf_multi.sh              # -thread 8 跑分，符合评分要求
├─ .github/workflows/ci.yml      # Linux/GCC 与 Clang CI，跑测试与格式检查
├─ .clang-format                 # 代码风格统一
├─ .gitignore
├─ README.md
└─ LICENSE
```