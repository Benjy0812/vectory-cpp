# C++ Package-Manifest Explorer Roadmap

Build an interview-worthy C++20 command-line project without letting its edge cases take over the learning. A milestone is complete when the behavior works, focused tests support it, and the user can explain the important choices.

The initial product is deliberately local and read-only: it inspects package manifests and produces plans. Downloading, privilege changes, or installing software are not required for the core portfolio project.

## Milestone 1: A trustworthy in-memory catalog

### Phase 1 — Toolchain and one manifest

- Configure one C++20 executable with target-based CMake.
- Model a minimal `PackageManifest` containing an ID, name, version, and description.
- Print one hard-coded manifest through a small presentation boundary.
- Enable compiler-appropriate warnings after detecting the active toolchain.
- Learn configure, compile, link, runtime, values, `std::string`, `const`, and references.
- Completion evidence: a clean checkout builds; the user can explain each build stage and the chosen parameter types.

### Phase 2 — Catalog operations

- Store manifests in a standard-library container.
- Find a manifest by stable package ID.
- Search names and descriptions with a clearly documented matching rule.
- Reject duplicate IDs at the catalog boundary.
- Learn structs or classes, invariants, containers, algorithms, lambdas, values, references, and iterator invalidation.
- Completion evidence: search and duplicate behavior have focused tests, and the user can explain why an ID is not a container index.

## Milestone 2: Load and validate real manifests

### Phase 3 — Define the manifest contract

- Specify required and optional fields before writing a parser.
- Create a few tiny valid and invalid sample manifests.
- Separate syntax/parsing failures from domain-validation failures.
- Start with only the rules required by current behavior: non-empty ID, parseable version text, and required display name.
- Learn boundary design, closed states with `enum class`, and choosing exceptions, optionals, or result values deliberately.
- Completion evidence: every current rule has one clear example and test; future rules remain in a backlog.

### Phase 4 — Add one parsing dependency

- Choose one maintained data-format library and integrate it through the project's CMake workflow.
- Parse one manifest file into a temporary representation, then validate it into a domain value.
- Preserve useful file, field, and reason context in errors.
- Learn third-party dependency integration, namespaces, conversions, RAII file handling, and dependency boundaries.
- Completion evidence: a malformed file, missing field, and valid file each produce deterministic outcomes; the user can explain what the dependency does and what the project still owns.

### Phase 5 — Load a local catalog

- Discover manifest files under a user-supplied sample directory.
- Define whether one bad file stops loading or is reported while valid files remain available.
- Sort displayed results deterministically.
- Keep terminal output separate from load and validation results.
- Learn filesystem paths, iteration, error propagation, object lifetime, and reproducible tests with temporary directories.
- Completion evidence: tests never touch real package data; load results identify successes and failures without partial hidden state.

## Milestone 3: Dependency-aware dry-run planning

### Phase 6 — Model dependencies

- Add a minimal dependency list to validated manifests.
- Report missing package IDs clearly.
- Keep version constraints out until exact requirements are defined.
- Learn associative containers, references versus copied values, and representing relationships without accidental ownership.
- Completion evidence: the catalog can explain which direct dependencies are present or missing.

### Phase 7 — Produce an install order

- Generate a dry-run order in which dependencies precede dependents.
- Detect cycles and report a useful cycle path or diagnostic.
- Make output deterministic when several valid orders exist.
- Learn graph traversal, visit states, recursion or an explicit stack, complexity, and regression testing.
- Completion evidence: tests cover a chain, shared dependency, missing dependency, independent packages, and a cycle; the user can trace one plan by hand.

### Phase 8 — Design the CLI

- Add focused commands such as `inspect`, `validate`, `search`, and `plan`.
- Define accepted syntax, standard output, diagnostic output, and exit codes before implementing each command.
- Keep parsing independent of catalog and planning behavior.
- Learn argument parsing, boundary errors, `std::optional` or a small result type, and integration tests.
- Completion evidence: invalid invocation cannot look successful and core behavior remains testable without launching a subprocess.

## Milestone 4: Interview-ready engineering evidence

### Phase 9 — Organize and test the codebase

- Separate manifest model, parsing, validation, catalog, planning, and CLI responsibilities.
- Split declarations and definitions when the codebase earns it; avoid speculative abstractions.
- Register focused tests with CTest.
- Add integration tests for representative command behavior.
- Completion evidence: one command runs deterministic tests, and a deliberately broken behavior makes the expected test fail.

### Phase 10 — Diagnostics and robustness

- Run the tests under supported sanitizers.
- Review compiler warnings and static-analysis findings rather than suppressing them blindly.
- Add contextual errors and protect state when loading fails.
- Apply a consistent formatter.
- Completion evidence: documented invalid input does not crash; findings are understood; no real system package data is modified.

### Phase 11 — CI and documentation

- Build and test a clean checkout in CI on at least one supported platform.
- Document requirements, configure/build/test commands, architecture, manifest examples, tradeoffs, and limitations.
- Include a short demo with deterministic sample data.
- Explain why the first release is a read-only planner rather than an installer.
- Completion evidence: another developer can build, test, and demo the project using only repository documentation.

### Phase 12 — Portfolio release

- Add installation or packaging rules for the explorer itself.
- Install into a temporary prefix and test the installed executable.
- Review public repository hygiene: license, contribution expectations if wanted, issue backlog, and no secrets or machine-specific paths.
- Tag a small first release only after its documented behavior is stable.
- Completion evidence: the release corresponds to tested source, and the user can explain one difficult bug, one lifetime choice, one dependency-planning decision, and one scope tradeoff.

## Optional extensions

Choose at most one after the core project is complete:

- semantic version constraints;
- SQLite catalog indexing behind the existing catalog boundary;
- richer query/filter expressions;
- benchmark a demonstrated slow catalog operation;
- a read-only remote catalog fetch with caching and integrity checks.

Actual software installation, privilege escalation, registry modification, rollback, package signatures, and arbitrary post-install scripts form a separate security-sensitive project phase. Do not add them merely to make the repository look more advanced.

## Git and learning rhythm

For each small behavior:

1. Predict the design or diagnostic before asking AI for code.
2. Define one completion check or focused test.
3. Implement one coherent slice.
4. Run the focused check, then the full suite.
5. Explain the important rule or tradeoff in the user's own words.
6. Review the diff and commit the intent.

Keep validation ideas, platform support, and optional features in issues or a short backlog so they do not interrupt the current slice.
