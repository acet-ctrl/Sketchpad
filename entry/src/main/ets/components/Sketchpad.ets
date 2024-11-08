import CommonConstant from '../common/CommonConstant'
import SketchpadEngine from '../interfaces/SketchpadEngine'

export let Engine: SketchpadEngine | undefined = undefined

@ComponentV2
export default struct Sketchpad {
  build() {
    XComponent({
      id: CommonConstant.XCOMPONENT_ID,
      type: XComponentType.SURFACE,
      libraryname: CommonConstant.XCOMPONENT_LIBRARYNAME
    })
      .focusable(true)
      .onLoad((engine) => {
        Engine = engine as SketchpadEngine
        Engine.loadRdb(getContext(this).databaseDir)
      })
      .width('100%')
      .height('100%')
  }
}