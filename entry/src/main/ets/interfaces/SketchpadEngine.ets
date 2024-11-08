export default interface SketchpadEngine {
  loadRdb(dir: string): void

  loadData(id: number): void

  switchTool(id: number): void

  saveData(): void
}