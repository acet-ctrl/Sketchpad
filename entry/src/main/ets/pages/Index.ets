import Sketchpad from '../components/Sketchpad'

@Entry
@ComponentV2
struct Index {
  build() {
    Row() {
      Column() {
        Sketchpad()
      }
      .width('100%')
    }
    .height('100%')
  }
}